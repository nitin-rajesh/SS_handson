#! /bin/bash
gcc p24_pgm.c
./a.out &
sleep 1
ps -efj | grep a.out