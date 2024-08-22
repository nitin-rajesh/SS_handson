#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/select.h>

int main(){
    struct timeval timeout;
    fd_set readfds;
    int ret;

    // Initialize the timeout for 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Clear the set and add STDIN (file descriptor 0) to the set
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Use select to wait for input on STDIN
    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        return 1;
    } else if (ret == 0) {
        printf("No data available within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("Data is available within 10 seconds.\n");
        }
    }

    return 0;
}
