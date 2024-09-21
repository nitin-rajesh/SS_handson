/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 17 September 2024
 * Problem 9: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sigint_handler(int signum) {
    printf("\nCaught SIGINT (Ctrl + C). Exiting...\n");
    exit(0);
}

int main(){
    signal(SIGINT, SIG_IGN);
    printf("SIGINT signal is now ignored. Press Ctrl + C, and nothing will happen.\n");

    for(int i = 0; i < 0x7FFFFFFF; i++);

    signal(SIGINT, sigint_handler);
    printf("SIGINT signal reset to default behavior. Press Ctrl + C to terminate the program.\n");

    pause();  

    return 0;
}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out
SIGINT signal is now ignored. Press Ctrl + C, and nothing will happen.
^C^C^CSIGINT signal reset to default behavior. Press Ctrl + C to terminate the program.
^C
Caught SIGINT (Ctrl + C). Exiting...
*/