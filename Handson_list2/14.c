/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 19 September 2024
 * Problem 14: Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fd[2]; //Two pipe files for read and write
    pid_t pid;
    char msg_out[] = "Hello Luigi, from Mario the plumber";
    char msg_in[100];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) { //Parent proc

        close(fd[0]);

        printf("Parent writing to the pipe: %s\n", msg_out);
        write(fd[1], msg_out, strlen(msg_out)+1); 
        
        close(fd[1]); 

    } else { //Child proc
        close(fd[1]); 

        read(fd[0], msg_in, sizeof(msg_in));

        printf("Child reading from the pipe: '%s'\n", msg_in);

        close(fd[0]);  
    }

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
Parent writing to the pipe: Hello Luigi, from Mario the plumber
Child reading from the pipe: 'Hello Luigi, from Mario the plumber'
*/
