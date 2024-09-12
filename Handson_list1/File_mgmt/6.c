/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 6: Write a program to take input from STDIN and display on STDOUT. 
 * Use only read/write system calls.
*/

#include<unistd.h>
#include<stdlib.h>

int main(){
    char buffer[128];

    int bytesin = read(STDIN_FILENO,buffer,sizeof(buffer));

    if(bytesin < 0)
        return 1;
    
    int bytesout = write(STDOUT_FILENO,buffer,bytesin);

    if(bytesout < 0)
        return 1;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out 
stdin i/p  
stdin i/p
*/