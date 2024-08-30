#! /bin/zsh
#  * Name: Nitin Kumar Rajesh
#  * Reg no: MT2024103
#  * Problem 1: Create the following types of a files using (i) shell command (ii) system call
#     a. soft link (symlink system call)
#     b. hard link (link system call)
#     c. FIFO (mkfifo Library Function or mknod system call)

mkdir temp
cd temp
touch temp_file
ln temp_file hardlink_file
ln -s temp_file softlink_file
mknod myfifo_file p
echo "Hello there" > myfifo_file &
cat myfifo_file
ls -li 
# rm hardlink_file softlink_file temp_file myfifo_file