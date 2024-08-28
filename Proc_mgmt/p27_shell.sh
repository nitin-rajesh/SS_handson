#! /bin/zsh
gcc p27_pgm.c

for i in $(seq 1 5);
do
    ./a.out $i
done