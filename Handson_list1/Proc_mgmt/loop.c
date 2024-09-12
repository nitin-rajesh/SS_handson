#include<stdio.h>  
#include<unistd.h>  
#include<sys/types.h>  
#include<time.h>
#include<unistd.h>
  
int main(){  
    getchar();
    nice(5);
    for(long i = 0; i < 0xFFFFFFFFF; i++);

}  