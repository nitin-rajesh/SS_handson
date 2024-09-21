/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 21 September 2024
 * Problem 28:  Write a program to change the exiting message queue permission. 
 * (use msqid_ds structure)
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<time.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[]) {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    if(argc < 2){
        printf("Usage: %s filepath",argv[0]);
        exit(0);
    }

    key = ftok(argv[1], 65);  
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    //Get stats of message queue
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT");
        exit(EXIT_FAILURE);
    }

    printf("Current permissions: %o\n", buf.msg_perm.mode & 0777);

    //Change perms to 0644 
    buf.msg_perm.mode = 0644;

    //Set new perms
    if (msgctl(msgid, IPC_SET, &buf) == -1) {
        perror("msgctl IPC_SET");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT");
        exit(EXIT_FAILURE);
    }

    printf("New permissions: %o\n", buf.msg_perm.mode & 0777);

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out temp/mynod_file 
Current permissions: 666
New permissions: 644
*/