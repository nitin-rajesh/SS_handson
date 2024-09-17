#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>

int main() {
    struct rlimit limit,new_limit;
    
    printf("Before setting new limit:\n");

    if (getrlimit(RLIMIT_STACK, &limit) == 0) 
        printf("Current Stack Limit: Soft = %ld, Hard = %ld\n", (long)limit.rlim_cur, (long)limit.rlim_max);
    else 
        perror("getrlimit");
    
    
    new_limit.rlim_cur = 10 * 1024 * 1024;  // 10 MB
    new_limit.rlim_max = RLIM_INFINITY;    // No limit
    
    if (setrlimit(RLIMIT_STACK, &new_limit) == 0) {
        printf("Stack limit updated successfully.\n");
    } else {
        perror("setrlimit");
    }
    
    // Print the updated stack limit
    printf("After setting new limit:\n");
    if (getrlimit(RLIMIT_STACK, &limit) == 0) 
        printf("Current Stack Limit: Soft = %ld, Hard = %ld\n", (long)limit.rlim_cur, (long)limit.rlim_max);
    else 
        perror("getrlimit");
    


    return 0;
}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % sudo ./a.out 
Password:
Before setting new limit:
Current Stack Limit: Soft = 8388608, Hard = 67104768
Stack limit updated successfully.
After setting new limit:
Current Stack Limit: Soft = 10485760, Hard = 9223372036854775807
*/