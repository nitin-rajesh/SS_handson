/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 8: Write a program to open a file in read only mode, read line by line and display each line as it is read.
 * Close the file when end of file is reached
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char **argv){
    char buffer[1];
    char output[BUFSIZ];

    char c = 0;
    int bytesout = 0;


    if(argc < 2){
        printf("Usage %s <filename>",argv[0]);
        return 0;
    }

    int fd = open(argv[1],O_RDONLY);
    int bytesin = -1;
    
    if (fd == -1){
        printf("Error opening file");
		return 1;
    }

    while (bytesin != 0)
    {

        bytesin = read(fd,buffer,1);
        printf("%c",buffer[0]);

        if(c != '\t' && buffer[0] == '\n')
            c = getchar();
    }

    close(fd);
    
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out temp/p3_copy.c 

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
*/