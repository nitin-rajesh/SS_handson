/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 28 August 2024
 * Problem 29: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(){
    struct sched_param sp;
    int policy;

    policy = sched_getscheduler(0);
    
    switch (policy) {
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
            break;
    }

    struct sched_param param;
    int policy = SCHED_FIFO;

    param.sched_priority = 10;

    if (sched_setscheduler(0, policy, &param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Scheduler set to SCHED_FIFO with priority %d\n", param.sched_priority);

}

/*
parallels@parallels-Parallels-Virtual-Platform:~/Documents/Code$ ./a.out 
Current scheduling policy: SCHED_OTHER
sched_setscheduler: Operation not permitted

parallels@parallels-Parallels-Virtual-Platform:~/Documents/Code$ sudo ./a.out 
[sudo] password for parallels:        
Current scheduling policy: SCHED_OTHER
Scheduler set to SCHED_FIFO with priority 10
*/