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