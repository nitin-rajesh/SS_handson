#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Problem 1: Create the following types of a files using (i) shell command (ii) system call
#     a. soft link (symlink system call)
#     b. hard link (link system call)
#     c. FIFO (mkfifo Library Function or mknod system call)

gcc loop.c 
./a.out &
pidval=`pgrep a.out`
lsof -p $pidval