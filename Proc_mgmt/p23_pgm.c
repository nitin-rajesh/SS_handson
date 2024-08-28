#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t childPid;
    int status;

    childPid = fork();

    if (childPid < 0)
        return 1;

    if(childPid == 0)
        exit(0);

    sleep(10);

    int pid = wait(&status); //Parent waits for child process to finish
}