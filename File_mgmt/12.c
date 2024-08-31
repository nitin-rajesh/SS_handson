/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 12: Write a program to find out the opening mode of a file. Use fcntl.
*/

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

/* Output:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % gcc p12_pgm.c 
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out 
Open mode: 8                      
*/