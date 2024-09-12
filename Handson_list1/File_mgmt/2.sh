#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Date: 22 August 2024
#  * Problem 2: Write a simple program to execute in an infinite loop at the background. 
#  * Go to /proc directory and identify all the process related information in the corresponding proc directory

gcc loop.c #Infinite loop pgm
./a.out &
pidval=`pgrep a.out`
lsof -p $pidval

# Output:
# nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./p2_proc.sh 
# COMMAND   PID        USER   FD   TYPE DEVICE SIZE/OFF                NODE NAME
# a.out   18568 nitinrajesh  cwd    DIR    1,4      832             1850808 /Users/nitinrajesh/Code/Software systems/System software/Hands_on_1/File_mgmt
# a.out   18568 nitinrajesh  txt    REG    1,4     4272             2184753 /Users/nitinrajesh/Code/Software systems/System software/Hands_on_1/File_mgmt/a.out
# a.out   18568 nitinrajesh  txt    REG    1,4  2714224 1152921500312526685 /usr/lib/dyld
# a.out   18568 nitinrajesh    0u   CHR    3,2      0t0                 314 /dev/null
# a.out   18568 nitinrajesh    1u   CHR   16,3  0t33804                1111 /dev/ttys003
# a.out   18568 nitinrajesh    2u   CHR   16,3  0t33804                1111 /dev/ttys003