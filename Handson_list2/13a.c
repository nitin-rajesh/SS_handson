#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void handle_sigcont(int signum){
    printf("Received SIGCONT signal. Process resumed.\n");
}

int main(){

    struct sigaction sa;
    sa.sa_handler = handle_sigcont;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGCONT, &sa, NULL) == -1) {
        perror("Error setting up SIGCONT handler");
        exit(1);
    }

    printf("Process %d waiting for SIGSTOP\n", getpid());

    while (1) {
        pause(); 
    }

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out &
[1] 6928
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % Process 6928 is waiting 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % 
[1]  + suspended (signal)  ./a.out
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % Received SIGCONT signal. Process resumed.

nitinrajesh@Nitins-MacBook-Pro Handson_list2 % 
 */