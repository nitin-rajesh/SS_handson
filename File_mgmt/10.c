/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 10: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){

    char *filename = "temp/seek_file.txt";

    int fd = open(filename,O_RDWR|O_CREAT|O_TRUNC,0644);

    if(fd < 0)
        return -1;

    char randBytes[10] = "First ten";
    char fileBytes[10] = "Next ten";

    int bytesOut = write(fd,randBytes,10);

    int seekval = lseek(fd,20,SEEK_SET);

    printf("lseek return: %d",seekval);

    bytesOut = write(fd,randBytes,10);
    close(fd);

    //system("od temp/seekfile.txt");


}

/* Output:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out 
lseek return: 20%                                                                                                                                                                         
nitinrajesh@Nitins-MacBook-Pro File_mgmt % cat temp/seek_file.txt 
First tenFirst ten%                                                                                                                                                                       
nitinrajesh@Nitins-MacBook-Pro File_mgmt % 
*/