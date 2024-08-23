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