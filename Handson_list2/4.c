/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 12 September 2024
 * Problem 4: Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
*/

#include<stdio.h>
#include<unistd.h>
#include<time.h>

// Inline assembly to get the Time Stamp Counter value
unsigned long long rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ (
        "rdtsc": "=a" (lo), "=d" (hi)  // Output to lo and hi for fine-grained timing
    );
    return ((unsigned long long)hi << 32) | lo;
}

int main(){
    unsigned long long start, end;
    int i;

    start = rdtsc();

    for (i = 0; i < 100; i++) 
        getppid();
    
    end = rdtsc();

    unsigned long long cycles = end - start;

    printf("Time taken for 100 getppid() calls: %llu CPU cycles, %f ms\n", cycles, cycles/1.4/CLOCKS_PER_SEC);

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out
Time taken for 100 getppid() calls: 127914 CPU cycles, 0.091367 ms
*/
