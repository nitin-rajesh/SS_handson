#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // This is the child process
        printf("In child proc - PID %d\n", getpid());
        sleep(2);  

        printf("Child sending SIGKILL to parent %d\n", getppid());
        kill(getppid(), SIGKILL);  
        
        printf("Child proc is now orphaned. Check status\n");
        sleep(10);  // Sleep to demonstrate orphan status

    } else {
        printf("Parent process (PID: %d) is running\n", getpid());

        for(int i = 0; i < 0x7FFFFFFF; i++);
    }

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./12.sh   
Parent process (PID: 89882) is running
In child proc - PID 89884
Child sending SIGKILL to parent 89882
Child proc is now orphaned. Check status
  501 89884     1   0  2:29PM ttys003    0:00.00 ./a.out          nitinrajesh      89878      0    1 SN+  s003 
  501 89926 89878   0  2:29PM ttys003    0:00.00 grep a.out       nitinrajesh      89878      0    1 S+   s003 
*/