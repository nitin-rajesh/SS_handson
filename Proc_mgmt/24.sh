#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Date: 22 August 2024
#  * Problem 24: Write a program to create an orphan process

gcc 24.c
./a.out &
sleep 1
ps -efj | grep a.out

# Output: 
# nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./p24_shell.sh 
#   501 59831     1   0 Sat04PM ??         0:00.60 ./a.out          nitinrajesh      59813      0    0 S      ?? 
#   501 97736 55433   0 10:17PM ttys012    0:00.00 grep a.out       nitinrajesh      97735      0    2 R+   s012 