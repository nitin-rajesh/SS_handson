/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 3: Write a program to create a file and print the file descriptor value. 
 * Use creat ( ) system call
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

/* Output:
File descriptor: 3% 
*/