#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

int main(int argc, char **argv){
    
    struct flock fl;

    char buffer[128];

    int fd = open("temp/ticket.txt",O_RDWR|O_CREAT,0644);

    memset(&fl,0,sizeof(fl));

    fl.l_type = F_WRLCK;
    int lockStat = fcntl(fd,F_SETLKW, &fl);

    printf("Setting write lock on file\n");

    if(lockStat == -1)
    {
        printf("Lock failed");
        return 1;
    }

    int bytesin = read(fd,buffer,127);
    buffer[bytesin] = '\0';        
    int ticketCount = atoi(buffer);

    printf("Ticket count: %d\n",ticketCount);

    getchar();

    ticketCount++;
    sprintf(buffer,"%d",ticketCount);

    lseek(fd,0,SEEK_SET);

    write(fd,buffer,128);

    printf("Incremented ticket count to %s\n",buffer);

    fl.l_type = F_UNLCK;

    lockStat = fcntl(fd,F_SETLK, &fl);

    if(lockStat == -1)
    {
        printf("Release lock failed");
        return 1;
    }

    close(fd);

}