#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<time.h>
#include<signal.h>
#include<stdlib.h>

void interval_handler(int signum) {
    time_t current_time;
    time(&current_time);

    printf("%s", ctime(&current_time));
}

int main(int argc, char **argv) {
    struct sigaction sa;
    struct itimerval timer;

    sa.sa_handler = interval_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        printf("Error setting up signal handler");
        return 1;
    }

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    int itimer_which = ITIMER_REAL;

    if(argc > 1){
        switch (atoi(argv[1]))
        {
        case 1:
            itimer_which = ITIMER_VIRTUAL;
            break;

        case 2:
            itimer_which = ITIMER_PROF;
            break;
        
        default:
            itimer_which = ITIMER_REAL;
        }
    }

    if (setitimer(itimer_which, &timer, NULL) == -1) {
        printf("Error setting timer");
        return 1;
    }

    while (1) {
        pause();
    }

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out
Tue Sep 17 19:11:56 2024
Tue Sep 17 19:12:06 2024
Tue Sep 17 19:12:16 2024
Tue Sep 17 19:12:26 2024
Tue Sep 17 19:12:36 2024
Tue Sep 17 19:12:46 2024
Tue Sep 17 19:12:56 2024
^C
*/