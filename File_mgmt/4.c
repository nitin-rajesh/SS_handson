/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 4: Write a program to open an existing file with read write mode. 
 * Try O_EXCL flag also.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    mkdir("temp",S_IRWXU);

    char *fname = "p4_pgm.c";
    int fileDesc = open(fname,O_RDWR);

    printf("File descriptor for O_RDWR: %d\n", fileDesc);

    close(fileDesc);

    fileDesc = open(fname,O_CREAT|O_EXCL);

    printf("File descriptor for O_CREAT|O_EXCL: %d\n", fileDesc);

    close(fileDesc);
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out      
File descriptor for O_RDWR: 3
File descriptor for O_CREAT|O_EXCL: -1
*/