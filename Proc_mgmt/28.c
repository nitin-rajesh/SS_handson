/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 28 August 2024
 * Problem 28: Write a program to get maximum and minimum real time priority
*/

#include<stdio.h>
#include<sched.h>

int main(){
    int p_max, p_min;

    p_max = sched_get_priority_max(SCHED_FIFO);

    p_min = sched_get_priority_min(SCHED_FIFO);
    if (p_max == -1 || p_min == -1) {
        printf("Failed to get priority");
        return 1;
    }

    printf("Max real-time priority: %d\n", p_max);
    printf("Min real-time priority: %d\n", p_min);

}

/* Output:
parallels@parallels-Parallels-Virtual-Platform:~/Documents/Code$ ./a.out 
Max real-time priority: 99
Min real-time priority: 1
*/