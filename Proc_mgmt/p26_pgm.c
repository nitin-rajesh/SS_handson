#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
    if(argc == 1)
        execlp("gcc","gcc","p22_pgm.c","-o","p22_from_p26",NULL);
    else
        execl("./p22_from_p26","./p22_from_p26","temp/pc_test.txt",NULL);
}