#! /bin/zsh

gcc 8.c

for i in $(seq 1 6);
do
    ./a.out $i
done
