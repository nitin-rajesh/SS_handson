#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Enter mode \n1. execl \n2. execlp \n3. execle \n4. execv \n5. execvp");
        return 0;
    }
    char *cmdpath = "/bin/ls";
    char *cmd = "ls";
    char *opt = "-Rl";
    char *vec[] = {cmdpath,opt,NULL};
    char *vecp[] = {cmd,opt,NULL};
    char *env[] = {"TEMP_FILE=p27_pgm.c"};

    switch (argv[1][0])
    {
    case '1':
        execl(cmdpath,cmdpath,"-Rl",NULL);
        break;
    case '2':
        execlp(cmd,cmd,opt,NULL);
        break;
    case '3':
        execle(cmdpath,cmdpath,opt,"$TEMP_FILE",env,NULL);
        break;
    case '4':
        execv(cmdpath,vec);
        break;
    case '5':
        execvp(cmd,vecp);
    default:
        break;
    }
}