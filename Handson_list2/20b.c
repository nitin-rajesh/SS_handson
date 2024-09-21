/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 20 September 2024
 * Problem 20: Write two programs so that both can communicate by FIFO 
 * -Use one way communication
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include <errno.h>

char FIFO_OUT[] = "temp/myfifo";

int main() {
    int fd_out;
    char message[] = "Hello from Mario!\n";

    if (mkfifo(FIFO_OUT, 0666) == -1 & errno != EEXIST) {
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
    return 0;
}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./20b
Message sent to the reader.
*/
