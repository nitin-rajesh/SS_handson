#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0)
        return 1;

    if(pid == 0)
        sleep(10); //child process
    else{
        exit(0); //parent process
    }
}