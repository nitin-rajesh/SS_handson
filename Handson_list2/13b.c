/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 19 September 2024
 * Problem 13: Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID to sigstop>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert argument to PID
    pid_t target_pid = atoi(argv[1]);

    // Send SIGSTOP signal to the target process
    if (kill(target_pid, SIGSTOP) == -1) {
        perror("Failed to send SIGSTOP");
        exit(1);
    }

    printf("Sent SIGSTOP signal to process %d\n", target_pid);

    sleep(5);

    if (kill(target_pid, SIGCONT) == -1) {
        perror("Failed to send SIGCONT");
        exit(EXIT_FAILURE);
    }

    printf("Sent SIGCONT signal to process (PID: %d)\n", target_pid);

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./sigstop 6928
Sent SIGSTOP signal to process (PID: 6928)
Sent SIGCONT signal to process (PID: 6928)
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % 
*/