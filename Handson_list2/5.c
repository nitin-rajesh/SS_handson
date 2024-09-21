/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 12 September 2024
 * Problem 5: Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
*/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main() {
    long result;

    // a. Maximum length of the arguments to the exec family of functions
    printf("Maximum length of arguments to exec functions: %ld bytes\n", sysconf(_SC_ARG_MAX));
    

    // b. Maximum number of simultaneous processes per user ID
    printf("Maximum number of simultaneous processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));

    // c. Number of clock ticks per second (jiffy)
    printf("Number of clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    

    // d. Maximum number of open files
    printf("Maximum number of open files: %ld\n", sysconf(_SC_OPEN_MAX));

    // e. Size of a page in bytes
    result = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", sysconf(_SC_PAGESIZE));

    // f. Total number of pages in the physical memory
    printf("Total number of pages in physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    // printf("Number of currently available pages in physical memory: %ld\n", result);

    return 0;
}

/* Output:
Maximum number of simultaneous processes per user ID: 1392
Number of clock ticks per second: 100
Maximum number of open files: 1048575
Size of a page: 4096 bytes
Total number of pages in physical memory: 2097152
*/