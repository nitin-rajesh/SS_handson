/* Name:
 * Reg no:
 * Problem statement
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    mkdir("temp",S_IRWXU);

    char *fname = "temp/rand_file";
    int fileDesc = creat(fname,S_IRWXO|S_IRUSR);

    printf("File descriptor: %d", fileDesc);

    close(fileDesc);
    remove(fname);

}