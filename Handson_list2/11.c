#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sigint_handler(int signum) {
    printf("\nCaught SIGINT (Ctrl + C). Exiting...\n");
    exit(0);
}

int main(){
    struct sigaction sa_ignore, sa_default;

    sa_ignore.sa_handler = SIG_IGN;  // Ignore SIGINT
    sa_ignore.sa_flags = 0;
    sigemptyset(&sa_ignore.sa_mask);

    sa_default.sa_handler = sigint_handler;  // Custom handler for SIGINT
    sa_default.sa_flags = 0;
    sigemptyset(&sa_default.sa_mask);

    if (sigaction(SIGINT, &sa_ignore, NULL) == -1) {
        perror("Error ignoring SIGINT");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT signal is now ignored. Press Ctrl + C and nothing will happen.\n");

    for(int i = 0; i < 0x7FFFFFFF; i++);


    if (sigaction(SIGINT, &sa_default, NULL) == -1) {
        perror("Error resetting SIGINT");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT signal reset to default action. Press Ctrl + C to terminate the program.\n");

    pause();  // Wait for signals
    

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
SIGINT signal is now ignored. Press Ctrl + C and nothing will happen.
^C^C^CSIGINT signal reset to default action. Press Ctrl + C to terminate the program.
^C
Caught SIGINT (Ctrl + C). Exiting...
 */