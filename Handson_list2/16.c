/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 19 September 2024
 * Problem 16: Write a program to send and receive data from parent to child vice versa. Use two way
communication.
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int pc_pipe[2]; //Two pipe files for read and write
    int cp_pipe[2];
    pid_t pid;
    char pc_msg_out[] = "Hello Luigi, from Mario the plumber";
    char cp_msg_out[] = "Hello Mario, from Luigi the apprenctice";
    char msg_in[100];

    if (pipe(pc_pipe) == -1 | pipe(cp_pipe) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) { //Parent proc

        close(pc_pipe[0]);

        printf("Parent writing to the pipe: %s\n", pc_msg_out);
        write(pc_pipe[1], pc_msg_out, strlen(pc_msg_out)+1); 
        
        close(pc_pipe[1]); 

        close(cp_pipe[1]); 

        read(cp_pipe[0], msg_in, sizeof(msg_in));

        printf("Parent reading from the pipe: '%s'\n", msg_in);

        close(cp_pipe[0]);  


    } else { //Child proc

        close(cp_pipe[0]);

        printf("Child writing to the pipe: %s\n", cp_msg_out);
        write(cp_pipe[1], cp_msg_out, strlen(cp_msg_out)+1); 
        
        close(cp_pipe[1]); 


        close(pc_pipe[1]); 

        read(pc_pipe[0], msg_in, sizeof(msg_in));

        printf("Child reading from the pipe: '%s'\n", msg_in);

        close(pc_pipe[0]);  
    }

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
Parent writing to the pipe: Hello Luigi, from Mario the plumber
Child writing to the pipe: Hello Mario, from Luigi the apprenctice
Child reading from the pipe: 'Hello Luigi, from Mario the plumber'
Parent reading from the pipe: 'Hello Mario, from Luigi the apprenctice'
*/
