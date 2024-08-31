#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Date: 28 August 2024
#  * Problem 27: Write a program to execute ls -Rl by the following system calls
# a. execl
# b. execlp
# c. execle
# d. execv
# e. execvp

gcc 27.c

for i in $(seq 1 5);
do
    ./a.out $i
done

# Output: 
# nitinrajesh@Nitins-MacBook-Pro Proc_mgmt % ./p27_shell.sh 
# total 192
# -rwxr-xr-x  1 nitinrajesh  staff  8784 Aug 31 16:43 a.out
# -rwxr-xr-x  1 nitinrajesh  staff  4272 Aug 31 16:29 loop
# -rw-r--r--  1 nitinrajesh  staff   152 Aug 27 10:28 loop.c
# -rw-r--r--  1 nitinrajesh  staff   849 Aug 31 16:28 p19_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   993 Aug 31 16:29 p20_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   581 Aug 31 16:30 p21_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff  8880 Aug 31 16:41 p22_from_p26
# -rw-r--r--  1 nitinrajesh  staff  1130 Aug 31 16:32 p22_pgm.c
# -rw-r--r--  1 nitinrajesh  staff  1276 Aug 31 16:34 p23_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   954 Aug 31 16:33 p23_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   819 Aug 31 16:38 p24_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   205 Aug 31 13:06 p24_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   963 Aug 31 16:39 p25_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   848 Aug 31 16:42 p26_pgm.c
# -rw-r--r--  1 nitinrajesh  staff  1025 Aug 31 13:09 p27_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   289 Aug 31 16:03 p27_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   533 Aug 31 13:20 p28_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   841 Aug 31 13:21 p29_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   637 Aug 31 13:22 p30_pgm.c
# drwxr-xr-x  5 nitinrajesh  staff   160 Aug 27 21:52 temp

# ./temp:
# total 24
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 31 16:40 fork_test.txt
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 31 16:41 pc_test.txt
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 27 21:41 testfile.txt
# total 192
# -rwxr-xr-x  1 nitinrajesh  staff  8784 Aug 31 16:43 a.out
# -rwxr-xr-x  1 nitinrajesh  staff  4272 Aug 31 16:29 loop
# -rw-r--r--  1 nitinrajesh  staff   152 Aug 27 10:28 loop.c
# -rw-r--r--  1 nitinrajesh  staff   849 Aug 31 16:28 p19_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   993 Aug 31 16:29 p20_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   581 Aug 31 16:30 p21_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff  8880 Aug 31 16:41 p22_from_p26
# -rw-r--r--  1 nitinrajesh  staff  1130 Aug 31 16:32 p22_pgm.c
# -rw-r--r--  1 nitinrajesh  staff  1276 Aug 31 16:34 p23_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   954 Aug 31 16:33 p23_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   819 Aug 31 16:38 p24_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   205 Aug 31 13:06 p24_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   963 Aug 31 16:39 p25_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   848 Aug 31 16:42 p26_pgm.c
# -rw-r--r--  1 nitinrajesh  staff  1025 Aug 31 13:09 p27_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   289 Aug 31 16:03 p27_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   533 Aug 31 13:20 p28_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   841 Aug 31 13:21 p29_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   637 Aug 31 13:22 p30_pgm.c
# drwxr-xr-x  5 nitinrajesh  staff   160 Aug 27 21:52 temp

# ./temp:
# total 24
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 31 16:40 fork_test.txt
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 31 16:41 pc_test.txt
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 27 21:41 testfile.txt
# ls: $TEMP_FILE: No such file or directory
# ls: }o�\016\001: No such file or directory
# total 192
# -rwxr-xr-x  1 nitinrajesh  staff  8784 Aug 31 16:43 a.out
# -rwxr-xr-x  1 nitinrajesh  staff  4272 Aug 31 16:29 loop
# -rw-r--r--  1 nitinrajesh  staff   152 Aug 27 10:28 loop.c
# -rw-r--r--  1 nitinrajesh  staff   849 Aug 31 16:28 p19_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   993 Aug 31 16:29 p20_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   581 Aug 31 16:30 p21_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff  8880 Aug 31 16:41 p22_from_p26
# -rw-r--r--  1 nitinrajesh  staff  1130 Aug 31 16:32 p22_pgm.c
# -rw-r--r--  1 nitinrajesh  staff  1276 Aug 31 16:34 p23_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   954 Aug 31 16:33 p23_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   819 Aug 31 16:38 p24_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   205 Aug 31 13:06 p24_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   963 Aug 31 16:39 p25_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   848 Aug 31 16:42 p26_pgm.c
# -rw-r--r--  1 nitinrajesh  staff  1025 Aug 31 13:09 p27_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   289 Aug 31 16:03 p27_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   533 Aug 31 13:20 p28_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   841 Aug 31 13:21 p29_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   637 Aug 31 13:22 p30_pgm.c
# drwxr-xr-x  5 nitinrajesh  staff   160 Aug 27 21:52 temp

# ./temp:
# total 24
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 31 16:40 fork_test.txt
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 31 16:41 pc_test.txt
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 27 21:41 testfile.txt
# total 192
# -rwxr-xr-x  1 nitinrajesh  staff  8784 Aug 31 16:43 a.out
# -rwxr-xr-x  1 nitinrajesh  staff  4272 Aug 31 16:29 loop
# -rw-r--r--  1 nitinrajesh  staff   152 Aug 27 10:28 loop.c
# -rw-r--r--  1 nitinrajesh  staff   849 Aug 31 16:28 p19_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   993 Aug 31 16:29 p20_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   581 Aug 31 16:30 p21_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff  8880 Aug 31 16:41 p22_from_p26
# -rw-r--r--  1 nitinrajesh  staff  1130 Aug 31 16:32 p22_pgm.c
# -rw-r--r--  1 nitinrajesh  staff  1276 Aug 31 16:34 p23_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   954 Aug 31 16:33 p23_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   819 Aug 31 16:38 p24_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   205 Aug 31 13:06 p24_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   963 Aug 31 16:39 p25_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   848 Aug 31 16:42 p26_pgm.c
# -rw-r--r--  1 nitinrajesh  staff  1025 Aug 31 13:09 p27_pgm.c
# -rwxr-xr-x  1 nitinrajesh  staff   289 Aug 31 16:03 p27_shell.sh
# -rw-r--r--  1 nitinrajesh  staff   533 Aug 31 13:20 p28_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   841 Aug 31 13:21 p29_pgm.c
# -rw-r--r--  1 nitinrajesh  staff   637 Aug 31 13:22 p30_pgm.c
# drwxr-xr-x  5 nitinrajesh  staff   160 Aug 27 21:52 temp

# ./temp:
# total 24
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 31 16:40 fork_test.txt
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 31 16:41 pc_test.txt
# -rw-r--r--@ 1 nitinrajesh  staff  51 Aug 27 21:41 testfile.txt