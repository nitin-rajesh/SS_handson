/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 28 August 2024
 * Problem 24: Write a program to create an orphan process
*/

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

/*
Output:
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % gcc p24_pgm.c 
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./a.out &
[1] 52524
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ps aux | grep Z 
  501 53492     1   0  4:36PM ttys005    0:00.00 ./a.out          nitinrajesh      53486      0    1 SN+  s005 
  501 53496 53486   0  4:36PM ttys005    0:00.00 grep a.out       nitinrajesh      53486      0    1 R+   s005 
*/