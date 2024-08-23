#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
    int fd, fd_dup, fd_dup2 = 20, fd_fcntl = 30;
    char *filename = "temp/dup_test.txt";
    char *text1 = "Original FD\n";
    char *text2 = "Dup FD\n";
    char *text3 = "Dup2 FD\n";
    char *text4 = "Fcntl FD\n";

    fd = creat(filename, 0744);

    fd_dup = dup(fd);
    fd_dup2 = dup2(fd,fd_dup2);
    fd_fcntl = fcntl(fd,F_DUPFD,fd_fcntl);

    write(fd, text1, strlen(text1));
    write(fd_dup, text2, strlen(text2));
    write(fd_dup2,text3,strlen(text3));
    write(fd_fcntl,text4,strlen(text4));


    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    system("cat temp/dup_test.txt");
    
    return 0;
}
