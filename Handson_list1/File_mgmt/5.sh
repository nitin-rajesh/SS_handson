#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Date: 22 August 2024
#  * Problem 5: Write a simple program to execute in an infinite loop at the background. 
#  * Go to /proc directory and identify all the process related information in the corresponding proc directory
# and check the file descriptor table at /proc/pid/fd

gcc file_loop.c # Create 5 files, then stalls
./a.out &
sleep 2
pidval=`pgrep a.out`
lsof -p $pidval

# nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./p5_shell.sh
# COMMAND   PID        USER   FD   TYPE DEVICE SIZE/OFF    NODE NAME
# a.out   21827 nitinrajesh  cwd    DIR    1,4      832 1850808 /Users/nitinrajesh/Code/Software systems/System software/Hands_on_1/File_mgmt
# a.out   21827 nitinrajesh  txt    REG    1,4     8800 2185058 /Users/nitinrajesh/Code/Software systems/System software/Hands_on_1/File_mgmt/a.out
# a.out   21827 nitinrajesh    0u   CHR    3,2      0t0     314 /dev/null
# a.out   21827 nitinrajesh    1u   CHR   16,3  0t37345    1111 /dev/ttys003
# a.out   21827 nitinrajesh    2u   CHR   16,3  0t37345    1111 /dev/ttys003
# a.out   21827 nitinrajesh    3w   REG    1,4        0 2185059 /Users/nitinrajesh/Code/Software systems/System software/Hands_on_1/File_mgmt/temp/one
# a.out   21827 nitinrajesh    4w   REG    1,4        0 2185060 /Users/nitinrajesh/Code/Software systems/System software/Hands_on_1/File_mgmt/temp/two
# a.out   21827 nitinrajesh    5w   REG    1,4        0 2185061 /Users/nitinrajesh/Code/Software systems/System software/Hands_on_1/File_mgmt/temp/three
# a.out   21827 nitinrajesh    6w   REG    1,4        0 2185062 /Users/nitinrajesh/Code/Software systems/System software/Hands_on_1/File_mgmt/temp/four
# a.out   21827 nitinrajesh    7w   REG    1,4        0 2185063 /Users/nitinrajesh/Code/Software systems/System software/Hands_on_1/File_mgmt/temp/five