#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main() {
    int fd, fd_dup, fd_dup2 = 20, fd_fcntl = 30;
    char *filename = "temp/dup_test.txt";

    fd = open(filename, O_APPEND);

    int openmode = fcntl(fd,F_GETFL);

    printf("Open mode: %d",openmode);

    close(fd);
    
    return 0;
}
