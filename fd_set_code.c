#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    fd_set rfds;
    struct timeval tv;
    int retval;

    FD_ZERO(&rfds);
    FD_SET(0,&rfds);

    tv.tv_sec = 5;
    tv.tv_usec  = 0;

    retval = select(1,&rfds,NULL,NULL,&tv);

    if(retval == -1)
        perror("Error occured");
    else if(retval)
        printf("Data available in 5 seconds");
    else
        printf("Data not available in 5 seconds");
}