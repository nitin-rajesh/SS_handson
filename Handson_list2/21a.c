#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

char FIFO_OUT[] = "temp/fifo1";
char FIFO_IN[] = "temp/fifo2";

int main() {
    int fd_out;
    char message[] = "Hello from Luigi!\n";

    //Write pipe
    if (mkfifo(FIFO_OUT, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    fd_out = open(FIFO_OUT, O_WRONLY);
    if (fd_out == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd_out, message, strlen(message)+1);

    close(fd_out);

    printf("Message sent to the reader.\n");

    sleep(5); //Wait for other side to open pipe

    //Read pipe
    int fd_in;
    char buffer[128];

    fd_in = open(FIFO_IN, O_RDONLY);
    if (fd_in == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(fd_in, buffer, sizeof(buffer));

    printf("Received message: %s", buffer);

    close(fd_in);

    unlink(FIFO_IN);


}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out           
Message sent to the reader.
Received message: Hello from Mario!
*/
