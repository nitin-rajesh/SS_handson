/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 14: Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>

int main(int argc, char **argv){

    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 0;
    }

    char *filename = argv[1];

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    unsigned char buffer[9];
    fread(buffer, 1, sizeof(buffer), file);
    fclose(file);
    buffer[8] = '\0';
    printf("File type from magic bytes: %s",buffer);

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out ~/Downloads/COAP\ 2024.pdf
File type from magic bytes: %PDF-1.3
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out ~/Downloads/samples-A.zip                    
File type from magic bytes: PK%
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out ~/Downloads/7677a510-54e6-4b16-b51b-f71709dae49e.JPG 
File type from magic bytes: ����
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out ~/Downloads/ParallelsDesktop-16.5.1-49187.dmg       
File type from magic bytes: x�c`C
*/