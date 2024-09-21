#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fd[2], status; //Two pipe files for read and write
    pid_t pid1, pid2;
    char msg_out[] = "Hello Luigi, from Mario the plumber";
    char msg_in[100];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid1 = fork();

    if(pid1 == 0) { //Child proc
        close(fd[0]);
        close(STDOUT_FILENO);
        dup(fd[1]);
        close(fd[1]); 
        execlp("ls","ls","-l",NULL);
    }

    pid2 = fork();

    if(pid2 == 0) { //Child proc

        close(fd[1]);
        close(STDIN_FILENO);
        dup(fd[0]);
        close(fd[0]); 
        execlp("wc","wc",NULL);

    } 

    close(fd[0]); 
    close(fd[1]);  

    waitpid(pid1,&status,0);
    waitpid(pid2,&status,0);

}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out  
      26     227    1436
*/