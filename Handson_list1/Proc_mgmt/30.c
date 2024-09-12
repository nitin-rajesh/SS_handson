/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 28 August 2024
 * Problem 30: Write a program to run a script at a specific time using a Daemon process
*/

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

/* Output:
Shell 1:
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./a.out 
Started daemon 59813

Shell 2:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ps
  PID TTY           TIME CMD
76284 ttys003    0:01.53 /bin/zsh -il
40332 ttys005    0:00.77 /bin/zsh -il
59831 ttys005    0:00.00 ./a.out
75475 ttys007    0:00.25 -zsh
95285 ttys007    0:00.02 zsh
95382 ttys007    0:00.45 zsh
36703 ttys011    0:00.05 -zsh
*/