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
