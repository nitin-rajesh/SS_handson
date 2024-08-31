#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Date: 28 August 2024
#  * Problem 20: Find out the priority of your running program. 
#  * Modify the priority with nice command.

priority=0
if [[ "$#" == "1" ]]; then
    priority=$1
fi
echo "Setting priority" $priority
gcc loop.c -o loop
nice -n $priority ./loop &
pidval=`pgrep loop`
ps -l -p $pidval

# Output:
# nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./p20_shell.sh  
# Setting priority 0
#   UID   PID  PPID        F CPU PRI NI       SZ    RSS WCHAN     S             ADDR TTY           TIME CMD
#   501 50415 50411     4006   0  31  5 33588144     12 -      SN+                 0 ttys005    0:00.00 ./loop
#
# nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./p20_shell.sh 10
# Setting priority 10
#   UID   PID  PPID        F CPU PRI NI       SZ    RSS WCHAN     S             ADDR TTY           TIME CMD
#   501 50490 50486     4006   0  31 15 33588144     12 -      SN+                 0 ttys005    0:00.00 ./loop