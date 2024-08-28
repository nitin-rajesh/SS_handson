#! /bin/zsh

gcc p23_pgm.c
./a.out &
sleep 1
ps aux | grep Z