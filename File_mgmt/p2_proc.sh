#! /bin/zsh
gcc loop.c 
./a.out &
pidval=`pgrep a.out`
lsof -p $pidval