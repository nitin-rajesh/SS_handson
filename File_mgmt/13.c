/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 13: Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select)
*/

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
    ret = select(1, &readfds, NULL, NULL, &timeout);

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

/* Output 1 (no data):
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out 
No data available within 10 seconds.
nitinrajesh@Nitins-MacBook-Pro File_mgmt % 

Output 2:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out 
Hello there
Data is available within 10 seconds.
*/