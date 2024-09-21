/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 17 September 2024
 * Problem 10: Write a separate program using sigaction system call to catch the following signals.
    a. SIGSEGV
    b. SIGINT
    c. SIGFPE
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>

void signal_handler(int signal_num) {
    switch (signal_num) {
        case SIGSEGV:
            printf("Caught SIGSEGV: Segmentation fault\n");
            exit(EXIT_FAILURE);
        case SIGINT:
            printf("Caught SIGINT: Interrupt signal (Ctrl + C)\n");
            break;
        case SIGFPE:
            printf("Caught SIGFPE: Floating-point exception\n");
            exit(EXIT_FAILURE);
        default:
            printf("Caught unknown signal: %d\n", signal_num);
            break;
    }
}

int main(int argc, char *argv[]){
    struct sigaction sigact;

    if(argc < 2){
        printf("Format: %s <sig option[1-3]>",argv[0]);
        return 0;

    }

    int option = atoi(argv[1]);

    // Set up the signal handler
    sigact.sa_handler = signal_handler;
    sigact.sa_flags = 0;  // No special flags
    sigemptyset(&sigact.sa_mask);  // No additional signals blocked during handler execution

    // Set up signal handling for SIGSEGV
    if (sigaction(SIGSEGV, &sigact, NULL) == -1) {
        perror("sigaction SIGSEGV");
        exit(EXIT_FAILURE);
    }

    // Set up signal handling for SIGINT
    if (sigaction(SIGINT, &sigact, NULL) == -1) {
        perror("sigaction SIGINT");
        exit(EXIT_FAILURE);
    }

    // Set up signal handling for SIGFPE
    if (sigaction(SIGFPE, &sigact, NULL) == -1) {
        perror("sigaction SIGFPE");
        exit(EXIT_FAILURE);
    }

    printf("Signal handlers installed. Process ID: %d\n", getpid());

    int* ptr,x,y;
    switch (option) {
        case 1:
            ptr = NULL;
            *ptr = 10;  
            break;
        case 2:
            x = 0;
            y = 10 / x; 
            break;
        case 3:
            printf("Press ^C");
            break;
    }

    pause();  // Wait for signals

    return 0;
}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 1
Signal handlers installed. Process ID: 41671
Caught SIGSEGV: Segmentation fault
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 2 
Signal handlers installed. Process ID: 41696
Caught SIGFPE: Floating-point exception
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 3
Signal handlers installed. Process ID: 41721
^CPress ^CCaught SIGINT: Interrupt signal (Ctrl + C)
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % 
*/