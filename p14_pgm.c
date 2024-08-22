#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>

int main(int argc, char **argv){

    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 0;
    }

    char *filename = argv[1];

    struct stat *file_stat;

    int statval = lstat(filename, file_stat);

    if(statval == -1)
        return 1;

    printf("File: %s\n", filename);
    printf("  Inode: %ld\n", (long)file_stat->st_ino);
    printf("  Number of hard links: %ld\n", (long)file_stat->st_nlink);
    printf("  UID: %u\n", file_stat->st_uid);
    printf("  GID: %u\n", file_stat->st_gid);
    printf("  Size: %ld bytes\n", (long)file_stat->st_size);
    printf("  Block size: %ld bytes\n", (long)file_stat->st_blksize);
    printf("  Number of blocks: %ld\n", (long)file_stat->st_blocks);

    printf("  Time of last access: %s", ctime(&file_stat->st_atime));
    printf("  Time of last modification: %s", ctime(&file_stat->st_mtime));
    printf("  Time of last status change: %s", ctime(&file_stat->st_ctime));

    return 0;

}