#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>

int main() {

    struct rlimit limit[9];

    char *limit_list[] = {
        "RLIMIT_CPU",
        "RLIMIT_FSIZE",
        "RLIMIT_DATA",
        "RLIMIT_STACK",
        "RLIMIT_CORE",
        "RLIMIT_RSS/RLIMIT_AS",
        "RLIMIT_MEMLOCK",
        "RLIMIT_NPROC",
        "RLIMIT_NOFILE"
    };

    for(int i = 0; i <= 8; i++)
        if(getrlimit(i,&limit[i]) == 0)
            printf("%-20s | Soft limit: %llu | Hard limit: %llu\n", limit_list[i], limit[i].rlim_cur, limit[i].rlim_max);
        else
            perror("getrlimit failed");

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
RLIMIT_CPU           | Soft limit: 9223372036854775807 | Hard limit: 9223372036854775807
RLIMIT_FSIZE         | Soft limit: 9223372036854775807 | Hard limit: 9223372036854775807
RLIMIT_DATA          | Soft limit: 9223372036854775807 | Hard limit: 9223372036854775807
RLIMIT_STACK         | Soft limit: 8388608 | Hard limit: 67104768
RLIMIT_CORE          | Soft limit: 0 | Hard limit: 9223372036854775807
RLIMIT_RSS/RLIMIT_AS | Soft limit: 9223372036854775807 | Hard limit: 9223372036854775807
RLIMIT_MEMLOCK       | Soft limit: 9223372036854775807 | Hard limit: 9223372036854775807
RLIMIT_NPROC         | Soft limit: 1392 | Hard limit: 2088
RLIMIT_NOFILE        | Soft limit: 1048575 | Hard limit: 9223372036854775807
*/