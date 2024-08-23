#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    mkdir("temp",S_IRWXU);

    char *fname = "p4_pgm.c";
    int fileDesc = open(fname,O_WRONLY);

    printf("File descriptor: %d\n", fileDesc);

    close(fileDesc);

    fileDesc = open(fname,O_EXCL);

    printf("File descriptor: %d\n", fileDesc);

    close(fileDesc);
}