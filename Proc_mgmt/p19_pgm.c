#include<stdio.h>  
#include<unistd.h>  
#include<sys/types.h>  
#include<time.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
    //volatile gets value from memory address instead of optimising
}
  
int main(){  
    clock_t start = rdtsc();
    pid_t pId = getpid();  
    clock_t stop = rdtsc();
    long long rt_diff = (stop - start);
    printf("Current PID: %d\ngetpid() time: %lld ns", pId,rt_diff);  
    return 0;  
}  