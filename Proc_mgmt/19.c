/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 28 August 2024
 * Problem 19: Write a program to find out time taken to execute getpid system call. 
 * Use time stamp counter
*/


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
    clock_t start = clock();
    pid_t pId;
    for(int i = 0; i < 128; i++)
        pId = getpid();  

    clock_t stop = clock();
    double rt_diff = (stop - start)*1000000./CLOCK_MONOTONIC;
    printf("Current PID: %d\ngetpid() time for 128 calls: %0.3f µs", pId,rt_diff);  
    return 0;  
}  

/*
./a.out      
Current PID: 49552
getpid() time for 128 calls: 4.000 µs%      
 */