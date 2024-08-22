/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Problem statement: 
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
    mkdir("temp",S_IRWXU);

    char *fname = "temp/temp_file";
    FILE *file = fopen(fname,"w");
    fclose(file);

    link(fname,"temp/hardlink_file");
    symlink(fname,"temp/softlink_file");

    mknod("temp/myfifo_file", S_IFIFO, 0);

    system("ls -li temp");

    // remove("temp/temp_file");
    // remove("temp/hardlink_file");
    // remove("temp/softlink_file");
    // remove("temp/myfifo_file");

}