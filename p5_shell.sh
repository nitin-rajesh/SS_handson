#! /bin/zsh
gcc file_loop.c 
./a.out &
sleep 2
pidval=`pgrep a.out`
lsof -p $pidval