#! /bin/zsh
# * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Date: 19 September 2024
#  * Problem 12: Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
#  the parent process from the child process.
gcc 12.c
./a.out &
sleep 5
ps -efj | grep a.out

# nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./12.sh   
# Parent process (PID: 89882) is running
# In child proc - PID 89884
# Child sending SIGKILL to parent 89882
# Child proc is now orphaned. Check status
#   501 89884     1   0  2:29PM ttys003    0:00.00 ./a.out          nitinrajesh      89878      0    1 SN+  s003 
#   501 89926 89878   0  2:29PM ttys003    0:00.00 grep a.out       nitinrajesh      89878      0    1 S+   s003 