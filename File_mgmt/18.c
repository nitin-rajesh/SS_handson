/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 18: Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

struct record{
    int index;
    char data[64];
};


int main(int argc, char **argv){

    int fd, lockStat;
    char filename[] = "temp/records.txt";

    struct flock fl;

    struct record rf;

    memset(&fl,0,sizeof(fl));

    if (argc < 3) {
        printf("Usage: %s <read/write> <record_index> <data>\n", argv[0]);
        return 0;
    }

    int recIndex = atoi(argv[2]);

    switch (argv[1][0])
    {
    case 'r':
        fd = open(filename,O_RDONLY|O_CREAT,0644);

        fl.l_type = F_RDLCK;
        lockStat = fcntl(fd,F_SETLKW, &fl);

        printf("Setting read lock on file\n");

        if(lockStat == -1)
        {
            printf("Lock failed");
            return 1;
        }

        lseek(fd,recIndex*sizeof(rf),SEEK_SET);
        read(fd,&rf,sizeof(rf));
        printf("-Record-\n{%d,'%s'}",rf.index,rf.data);
        break;

    case 'w':
        fd = open(filename,O_RDWR|O_CREAT,0644);

        fl.l_type = F_WRLCK;
        lockStat = fcntl(fd,F_SETLKW, &fl);

        printf("Setting write lock on file\n");

        if(lockStat == -1)
        {
            printf("Lock failed");
            return 1;
        }
        
        struct record rf = {atoi(argv[2]),"."};

        if(argc > 3)
            strcpy(rf.data,argv[3]);

        lseek(fd,0,SEEK_END);

        write(fd,&rf,sizeof(rf));
        printf("-Inserted rec-\n{%d,'%s'}",rf.index,rf.data);
        break;
    
    default:
        break;
    }

    getchar();

    fl.l_type = F_UNLCK;

    lockStat = fcntl(fd,F_SETLK, &fl);

    if(lockStat == -1)
    {
        printf("Release lock failed");
        return 1;
    }

    close(fd);

}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out w 1 One                  
Setting write lock on file
-Inserted rec-
{1,'One'}
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out w 2 Two
Setting write lock on file
-Inserted rec-
{2,'Two'}
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out w 21 TwentyOne
Setting write lock on file
-Inserted rec-
{21,'TwentyOne'}
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out r 0 
Setting read lock on file
-Record-
{1,'One'}
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out r 1
Setting read lock on file
-Record-
{2,'Two'}
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out r 2
Setting read lock on file
-Record-
{3,'Three'}
*/