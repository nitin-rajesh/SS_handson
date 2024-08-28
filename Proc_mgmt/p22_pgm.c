#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[]){
    pid_t pid;

    char *fname = "temp/fork_test.txt";

    if(argc > 1)
        fname = argv[1];

    char childMsg[64];
    char parentMsg[64];

    int fd = creat(fname,0644);

    pid = fork();


    if (pid < 0) {
        printf("Fork Failed\n");
        close(fd);
        return 1;
    }
    if (pid == 0) {
        sprintf(childMsg,"In child process...%d\n",getpid());
        write(fd,childMsg,strlen(childMsg));
    }
    else {
        sprintf(parentMsg,"In parent process...%d\n",getpid());
        write(fd,parentMsg,strlen(parentMsg));
        close(fd);
    }
}
