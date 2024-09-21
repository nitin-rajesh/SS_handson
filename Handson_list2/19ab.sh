#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Date: 19 September 2024
#  * Problem 19: Create a FIFO file by
# a. mknod command
# b. mkfifo command
# c. use strace command to find out, which command (mknod or mkfifo) is better.
# c. mknod system call
# d. mkfifo library function

cd temp
mknod nodpipe p
mkfifo fifopipe

# Output:
# nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ls -la temp
# total 0
# drwxr-xr-x   4 nitinrajesh  staff  128 Sep 19 14:42 .
# drwxr-xr-x  30 nitinrajesh  staff  960 Sep 19 14:44 ..
# prw-r--r--   1 nitinrajesh  staff    0 Sep 19 14:42 fifopipe
# prw-r--r--   1 nitinrajesh  staff    0 Sep 19 14:42 nodpipe