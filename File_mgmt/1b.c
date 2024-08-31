/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 1: Create the following types of a files using (i) shell command (ii) system call
    a. soft link (symlink system call)
    b. hard link (link system call)
    c. FIFO (mkfifo Library Function or mknod system call)
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
    mkdir("temp",S_IRWXU);

    char *fname = "temp/temp_file";
    FILE *file = fopen(fname,"w");
    fclose(file);

    link(fname,"temp/hardlink_file");
    symlink(fname,"temp/softlink_file");

    mknod("temp/myfifo_file", S_IFIFO, 0);

    system("ls -li temp");

    // remove("temp/temp_file");
    // remove("temp/hardlink_file");
    // remove("temp/softlink_file");
    // remove("temp/myfifo_file");

}

/* Output
total 48
1300109 -rwxr--r--@ 1 nitinrajesh  staff   36 Aug 12 22:05 dup_test.txt
2184621 -rw-r--r--  2 nitinrajesh  staff    0 Aug 31 15:09 hardlink_file
2184625 p---------  1 nitinrajesh  staff    0 Aug 31 15:09 myfifo_file
1379104 -r----x--x  1 nitinrajesh  staff  696 Aug 13 16:23 p7_copy.c
1795434 -rw-r--r--  1 nitinrajesh  staff  204 Aug 21 22:35 records.txt
1298391 --w-r-x---  1 nitinrajesh  staff   30 Aug 12 18:57 seek_file.txt
1298285 --w-r-x---  1 nitinrajesh  staff   30 Aug 12 18:54 seekfile.txt
2184624 lrwxr-xr-x  1 nitinrajesh  staff   14 Aug 31 15:09 softlink_file -> temp/temp_file
2184621 -rw-r--r--  2 nitinrajesh  staff    0 Aug 31 15:09 temp_file
1781557 -rw-r--r--  1 nitinrajesh  staff  128 Aug 21 19:13 ticket.txt
*/