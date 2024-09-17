#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/time.h>

void signal_handler(int signal_num) {    
    switch (signal_num) {
        case SIGSEGV:
            printf("Caught SIGSEGV: Segmentation fault\n");
            exit(1);
        case SIGINT:
            printf("Caught SIGINT: Interrupt signal (Ctrl + C)\n");
            break;
        case SIGFPE:
            printf("Caught SIGFPE: Floating point exception\n");
            exit(1);
        case SIGALRM:
            printf("Caught SIGALRM: Alarm signal\n");
            break;
        case SIGVTALRM:
            printf("Caught SIGVTALRM: Virtual timer alarm signal\n");
            break;
        case SIGPROF:
            printf("Caught SIGPROF: Profiling timer alarm signal\n");
            break;
        default:
            printf("Caught unknown signal: %d\n", signal_num);
            break;
    }
}

int main(int argc, char *argv[]) {
    // Register signal handler for various signals
    if(argc < 2){
        printf("Format: %s <sig option[1-6]>",argv[0]);
        return 0;
    }
    
    int option = atoi(argv[1]);

    signal(SIGSEGV,signal_handler);
    signal(SIGINT,signal_handler);
    signal(SIGFPE,signal_handler);
    signal(SIGALRM,signal_handler);
    signal(SIGVTALRM,signal_handler);
    signal(SIGPROF,signal_handler);

    int *ptr,x,y;
    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;


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
            alarm(2); 
            pause(); 
            break;
        case 4:
            setitimer(ITIMER_REAL, &timer, NULL);
            pause(); 
            break;
        case 5:
            setitimer(ITIMER_VIRTUAL, &timer, NULL);
            pause();  
            break;
        case 6:
            setitimer(ITIMER_PROF, &timer, NULL);
            pause();  
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./8.sh 
Caught SIGSEGV: Segmentation fault
Caught SIGFPE: Floating point exception
Caught SIGALRM: Alarm signal
Caught SIGALRM: Alarm signal
^CCaught SIGINT: Interrupt signal (Ctrl + C)
*/