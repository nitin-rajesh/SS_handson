/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 20 September 2024
 * Problem 22: Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

char FIFO_FILE[] = "temp/myfifo";

int main() {
    int fd;
    fd_set read_fds;
    struct timeval timeout;
    char buffer[128];
    int ret;

    // Create the FIFO if it doesn't exist
    if (mkfifo(FIFO_FILE, 0666) == -1 & errno != EEXIST) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Open the FIFO for reading
    fd = open(FIFO_FILE, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Initialize the file descriptor set
    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    // Set the timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Use select to wait for data on the FIFO
    ret = select(fd+1, &read_fds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        close(fd);
        exit(1);

    } else if (ret == 0) {
        printf("Timeout: No data within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &read_fds)) {
            int bytes_in = read(fd, buffer, sizeof(buffer));
            buffer[bytes_in] = '\0';
            printf("Message: %s",buffer);

        }
    }

    close(fd);
    unlink(FIFO_FILE);  
    
    return 0;
}

/*
Output: 
1) 10 second wait-
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out       
Timeout: No data within 10 seconds.

2) Data written
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
Message: Hello from Mario!
*/