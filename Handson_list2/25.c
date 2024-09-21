/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 20 September 2024
 * Problem 25:  Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
    a. access permission
    b. uid, gid
    c. time of last message sent and received
    d. time of last change in the message queue
    d. size of the queue
    f. number of messages in the queue
    g. maximum number of bytes allowed
    h. pid of the msgsnd and msgrcv
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<time.h>
#include<errno.h>

int main(int argc, char *argv[]) {
    key_t key;
    int msgid;
    struct msqid_ds buf; // Structure to hold message queue information

    if(argc < 2){
        printf("Usage: %s filepath",argv[0]);
        exit(0);
    }

    key = ftok(argv[1], 65);  
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Get info about the message queue
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Access permissions: %o\n", buf.msg_perm.mode);

    printf("Owner's UID: %d\n", buf.msg_perm.uid);
    printf("Owner's GID: %d\n", buf.msg_perm.gid);

    printf("Time of last message sent: %s\n", ctime(&buf.msg_stime));

    printf("Time of last message received: %s\n", ctime(&buf.msg_rtime));

    printf("Time of last change in message queue: %s\n", ctime(&buf.msg_ctime));

    printf("Current number of bytes in the queue: %lu\n", buf.msg_cbytes);

    printf("Number of messages in the queue: %lu\n", buf.msg_qnum);

    printf("Maximum number of bytes allowed in the queue: %lu\n", buf.msg_qbytes);

    printf("PID of the last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of the last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/* Output: 
Access permissions: 666
Owner's UID: 501
Owner's GID: 20
Time of last message sent: Thu Jan  1 05:30:00 1970

Time of last message received: Thu Jan  1 05:30:00 1970

Time of last change in message queue: Sat Sep 21 09:49:17 2024

Current number of bytes in the queue: 0
Number of messages in the queue: 0
Maximum number of bytes allowed in the queue: 2048
PID of the last msgsnd: 0
PID of the last msgrcv: 0
*/