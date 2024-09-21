#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int pipe1[2], pipe2[2], status; //Two pipe files for read and write
    pid_t pid1, pid2, pid3;
    char msg_out[] = "Hello Luigi, from Mario the plumber";
    char msg_in[100];

    if (pipe(pipe1) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    if (pipe(pipe2) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid1 = fork();

    if(pid1 == 0) { //Child proc

        close(pipe2[0]); //Close all unused pipes per fork
        close(pipe2[1]); //to avoid infinite waiting

        close(pipe1[0]);
        dup2(pipe1[1],STDOUT_FILENO);
        close(pipe1[1]); 
        execlp("ls","ls","-l",NULL);
    }

    pid2 = fork();

    if(pid2 == 0) { //Child proc

        close(pipe1[1]);
        dup2(pipe1[0],STDIN_FILENO);
        close(pipe1[0]); 

        close(pipe2[0]);
        dup2(pipe2[1],STDOUT_FILENO);
        close(pipe2[1]); 

        execlp("grep","grep","^d",NULL);

    } 

    pid3 = fork();

    if(pid3 == 0) { //Child proc

        close(pipe1[0]);
        close(pipe1[1]);

        close(pipe2[1]);
        dup2(pipe2[0],STDIN_FILENO);
        close(pipe2[0]); 

        execlp("wc","wc",NULL);

    } 


    close(pipe1[0]); 
    close(pipe1[1]);  

    close(pipe2[0]); 
    close(pipe2[1]); 

    waitpid(pid1,&status,0);
    waitpid(pid2,&status,0);
    waitpid(pid3,&status,0);

}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
       1       9      60
*/