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