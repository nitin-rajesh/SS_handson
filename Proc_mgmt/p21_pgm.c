#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Fork Failed\n");
        return 1;
    }
    if (pid == 0) {
        printf("In child process...\nChild PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else {
        printf("In parent process...\nParent PID = %d, Child PID = %d\n", getpid(), pid);
    }
}
