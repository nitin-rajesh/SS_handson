#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main() {
    char *filenames[] = {"one","two","three","four","five"};
    int fdlist[5];
    for(int i = 0; i < 5; i++){
        char temp[64] = "temp/";
        strcat(temp,filenames[i]);
        fdlist[i] = creat(temp,O_CREAT);
    }

    for(int j = 0;j < 2147483647;j++);

    for(int i = 0; i < 5; i++){
        char temp[64] = "temp/";
        strcat(temp,filenames[i]);
        close(fdlist[i]);
        remove(temp);
    }
}