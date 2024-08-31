/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 22 August 2024
 * Problem 9: Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>


int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 0;
    }

    char *file_path = argv[1];

    struct stat file_stat;

    // Retrieve file status
    int statval = stat(file_path, &file_stat);

    if(statval == -1)
        return 1;

    printf("File: %s\n", file_path);
    printf("  Inode: %ld\n", (long)file_stat.st_ino);
    printf("  Number of hard links: %ld\n", (long)file_stat.st_nlink);
    printf("  UID: %u\n", file_stat.st_uid);
    printf("  GID: %u\n", file_stat.st_gid);
    printf("  Size: %ld bytes\n", (long)file_stat.st_size);
    printf("  Block size: %ld bytes\n", (long)file_stat.st_blksize);
    printf("  Number of blocks: %ld\n", (long)file_stat.st_blocks);

    printf("  Time of last access: %s", ctime(&file_stat.st_atime));
    printf("  Time of last modification: %s", ctime(&file_stat.st_mtime));
    printf("  Time of last status change: %s", ctime(&file_stat.st_ctime));

}

/*
nitinrajesh@Nitins-MacBook-Pro File_mgmt % ./a.out temp/dup_test.txt 
File: temp/dup_test.txt
  Inode: 1300109
  Number of hard links: 1
  UID: 501
  GID: 20
  Size: 36 bytes
  Block size: 4096 bytes
  Number of blocks: 8
  Time of last access: Sat Aug 31 12:21:00 2024
  Time of last modification: Mon Aug 12 22:05:57 2024
  Time of last status change: Sat Aug 31 12:20:26 2024
*/