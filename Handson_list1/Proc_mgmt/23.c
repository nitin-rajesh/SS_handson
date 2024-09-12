/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 28 August 2024
 * Problem 23: Write a program to create a Zombie state of the running program.
*/

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

/*
Output: 
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % gcc p23_pgm.c 
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./a.out &
[1] 52519
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ps aux | grep Z
USER               PID  %CPU %MEM      VSZ    RSS   TT  STAT STARTED      TIME COMMAND
nitinrajesh      52521   0.0  0.0        0      0 s005  ZN    4:33PM   0:00.00 <defunct>
root             59668   0.0  0.0        0      0   ??  Z    10:55AM   0:00.00 <defunct>
root             49770   0.0  0.0        0      0   ??  Z    Thu06PM   0:00.00 <defunct>
root             87477   0.0  0.0        0      0   ??  Z    Wed09PM   0:00.00 <defunct>
nitinrajesh      52567   0.0  0.0 33596884    472 s005  R+    4:34PM   0:00.00 grep Z
root             87406   0.0  0.0        0      0   ??  Z    Wed09PM   0:00.00 <defunct>

*/