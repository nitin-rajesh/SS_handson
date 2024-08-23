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