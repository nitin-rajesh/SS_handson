#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){

    char *filename = "temp/seek_file.txt";

    int fd = open(filename,O_RDWR|O_CREAT);

    if(fd < 0)
        return -1;

    char randBytes[10];
    char fileBytes[10];

    int bytesOut = write(fd,randBytes,10);

    int seekval = lseek(fd,10,SEEK_CUR);

    printf("lseek return: %d",seekval);

    bytesOut = write(fd,randBytes,10);
    close(fd);

    //system("od temp/seekfile.txt");


}