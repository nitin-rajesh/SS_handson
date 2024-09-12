#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Date: 28 August 2024
#  * Problem 20: Find out the priority of your running program. 
#  * Modify the priority with nice command.

gcc 23.c
./a.out &
sleep 1
ps aux | grep Z

# Output: 
# nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./p23_shell.sh 
# USER               PID  %CPU %MEM      VSZ    RSS   TT  STAT STARTED      TIME COMMAND
# nitinrajesh      51883   0.0  0.0        0      0 s005  ZN+   4:32PM   0:00.00 <defunct>
# root             59668   0.0  0.0        0      0   ??  Z    10:55AM   0:00.00 <defunct>
# root             49770   0.0  0.0        0      0   ??  Z    Thu06PM   0:00.00 <defunct>
# root             87477   0.0  0.0        0      0   ??  Z    Wed09PM   0:00.00 <defunct>
# nitinrajesh      51895   0.0  0.0 33591656     92 s005  U+    4:32PM   0:00.01 grep Z
# root             87406   0.0  0.0        0      0   ??  Z    Wed09PM   0:00.00 <defunct>
