/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Problem 1: Create the following types of a files using (i) shell command (ii) system call
    a. soft link (symlink system call)
    b. hard link (link system call)
    c. FIFO (mkfifo Library Function or mknod system call)
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