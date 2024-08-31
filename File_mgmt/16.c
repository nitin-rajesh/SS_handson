/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 16: Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

int main(int argc, char **argv){

    struct flock fl;

    fl.l_pid = getpid();

    if (argc < 2) {
        printf("Usage: %s <file_path> <lock_opt>\n", argv[0]);
        return 0;
    }

    char *filepath = argv[1];

    int fd = open(filepath,O_RDWR);

    if(fd == -1)
    {
        printf("File open failed");
        return 1;
    }   

    memset(&fl,0,sizeof(fl));
    fl.l_type = F_WRLCK;

    if(argc > 2 && argv[2][0] == 'r')
        fl.l_type = F_RDLCK;


    printf("Locking %s\n",filepath);

    int lockStat = fcntl(fd,F_SETLKW, &fl);

    if(lockStat == -1)
    {
        printf("Lock failed");
        return 1;
    }
    printf("Enabled %s lock on %s\n",fl.l_type==F_WRLCK?"write":"read",filepath);

    getchar();

    fl.l_type = F_UNLCK;

    lockStat = fcntl(fd,F_SETLK, &fl);

    if(lockStat == -1)
    {
        printf("Release lock failed");
        return 1;
    }

    printf("Released lock on %s\n",filepath);

    close(fd);

}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out temp/dup_test.txt r
Locking temp/dup_test.txt
Enabled read lock on temp/dup_test.txt

Released lock on temp/dup_test.txt
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out temp/dup_test.txt w
Locking temp/dup_test.txt
Enabled write lock on temp/dup_test.txt

Released lock on temp/dup_test.txt
*/