/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 15: Write a program to display the environmental variable of the user (use environ).
*/

#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(){

    // int i = 0;
    // while(environ[i]) {
    //     printf("%d: %s\n", i+1, environ[i]);
    //     i++;
    // }
    printf("%s",environ[1]);

    
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out 
USER=nitinrajesh
*/