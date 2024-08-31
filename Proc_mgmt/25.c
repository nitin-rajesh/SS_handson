/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 28 August 2024
 * Problem 25: Write a program to create three child processes. 
 * The parent should wait for a particular child (use waitpid system call)
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid[3];
    int status;

    if((pid[0] = fork())){
        waitpid(pid[0],&status,WNOHANG);
        if((pid[1] = fork())){
            waitpid(pid[1],&status,WNOHANG);
            if((pid[2] = fork())){
                printf("Parent pid: %d\n",getpid());
                waitpid(pid[2],&status,WNOHANG);
            }
            else printf("Child proc 3: %d\n",getpid());
        }
        else printf("Child proc 2: %d\n",getpid());
    }
    else printf("Child proc 1: %d\n",getpid());

    
}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./a.out 
Child proc 1: 54599
Parent pid: 54581
Child proc 2: 54600
Child proc 3: 54601
*/