#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

// Signal handler for SIGINT (only used when resetting to default behavior)
void sigint_handler(int signum) {
    printf("\nCaught SIGINT signal (Ctrl + C) - Default action restored.\n");
    exit(0);
}

int main() {
    // Ignore the SIGINT signal
    signal(SIGINT, SIG_IGN);
    printf("SIGINT signal is now ignored. Press Ctrl + C, and nothing will happen.\n");

    for(int i = 0; i < 0x7FFFFFFF; i++);

    // Reset SIGINT signal to its default action
    signal(SIGINT, sigint_handler);
    printf("SIGINT signal reset to default behavior. Press Ctrl + C to terminate the program.\n");

    // Infinite loop to keep the program running, waiting for the user to press Ctrl + C
    while (1) {
        pause();  // Wait for signal
    }

    return 0;
}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out
SIGINT signal is now ignored. Press Ctrl + C, and nothing will happen.
^C^C^CSIGINT signal reset to default behavior. Press Ctrl + C to terminate the program.
^C
Caught SIGINT signal (Ctrl + C) - Default action restored.
*/