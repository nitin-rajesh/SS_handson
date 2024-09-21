#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Date: 17 September 2024
#  * Problem 8: Write a separate program using signal system call to catch the following signals.
#     a. SIGSEGV
#     b. SIGINT
#     c. SIGFPE
#     d. SIGALRM (use alarm system call)
#     e. SIGALRM (use setitimer system call)
#     f. SIGVTALRM (use setitimer system call)
#     g. SIGPROF (use setitimer system call)

gcc 8.c

for i in $(seq 1 6);
do
    ./a.out $i
done
