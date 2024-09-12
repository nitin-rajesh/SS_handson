/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 28 August 2024
 * Problem 21: Write a program, call fork and print the parent and child process id.
*/

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

/*
Output:
In parent process...
Parent PID = 51252, Child PID = 51253
In child process...
Child PID = 51253, Parent PID = 51252
*/