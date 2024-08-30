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
