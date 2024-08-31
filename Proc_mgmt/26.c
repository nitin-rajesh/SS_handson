/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 28 August 2024
 * Problem 26: Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
    if(argc == 1)
        execlp("gcc","gcc","p22_pgm.c","-o","p22_from_p26",NULL);
    else
        execl("./p22_from_p26","./p22_from_p26","temp/pc_test.txt",NULL);
}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % gcc p26_pgm.c 
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./a.out 
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./a.out x
nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % cat temp/pc_test.txt 
In parent process...55755
In child process...55756
 */