/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 19 September 2024
 * Problem 19: Create a FIFO file by
    a. mknod command
    b. mkfifo command
    c. use strace command to find out, which command (mknod or mkfifo) is better.
    c. mknod system call
    d. mkfifo library function
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){

    mknod("temp/mynod_file", S_IFIFO, 0);
    mkfifo("temp/myfifo_file", S_IFIFO);


}

/* Output
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ls -la temp 
total 0
drwxr-xr-x   6 nitinrajesh  staff  192 Sep 19 14:47 .
drwxr-xr-x  30 nitinrajesh  staff  960 Sep 19 14:47 ..
prw-r--r--   1 nitinrajesh  staff    0 Sep 19 14:42 fifopipe
p---------   1 nitinrajesh  staff    0 Sep 19 14:47 myfifo_file
p---------   1 nitinrajesh  staff    0 Sep 19 14:47 mynod_file
prw-r--r--   1 nitinrajesh  staff    0 Sep 19 14:42 nodpipe
*/