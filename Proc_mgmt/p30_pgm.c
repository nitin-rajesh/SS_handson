#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){

    pid_t pid;

    pid = fork();

    if(pid < 0)
        exit(1);

    if(pid == 0){
        chdir("~");
        umask(0);

        while (1)
        {
            sleep(10);
            printf("Daemon process %d running",getpid());
        }

    }
    else{
        printf("Started daemon %d\n",getpid());
        exit(0);
    }

}
