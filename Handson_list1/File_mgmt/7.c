/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 7: Write a program to copy file1 into file2 ($cp file1 file2).
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char **argv){

    if (argc < 3) {
        printf("Usage: %s <source_file> <copy_file>\n", argv[0]);
        return 0;
    }

    char buffer[BUFSIZ];

    int sourcefile = open(argv[1],O_RDONLY);
    int destfile = open(argv[2],O_CREAT|O_WRONLY,0644);

    int bytesin = -1;

    while(bytesin != 0){
        bytesin = read(sourcefile,buffer,BUFSIZ);

        if(bytesin == -1){
            printf("Error reading file");
            return 1;
        }

        write(destfile,buffer,bytesin);
    }

    close(sourcefile);
    close(destfile);

    return 0;

    // system("cp p7_pgm.c p7_copy.c");
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out p3_pgm.c temp/p3_copy.c
nitinrajesh@Nitins-MacBook-Pro File_mgmt % cat temp/p3_copy.c 

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

}%                                                                                                                                                                                       
*/