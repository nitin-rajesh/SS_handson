#include<stdio.h>  
#include<unistd.h>  
#include<sys/types.h>  
#include<time.h>
  
int main(){  
    clock_t start = clock();
    pid_t pId = getpid();  
    clock_t stop = clock();
    double rt_diff = (stop - start)*1000000./CLOCKS_PER_SEC;
    printf("Current PID: %d\ngetpid() time: %0.3fµs", pId,rt_diff);  
    return 0;  
}  