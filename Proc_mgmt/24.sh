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
#   501 53492     1   0  4:36PM ttys005    0:00.00 ./a.out          nitinrajesh      53486      0    1 SN+  s005 
#   501 53496 53486   0  4:36PM ttys005    0:00.00 grep a.out       nitinrajesh      53486      0    1 R+   s005 