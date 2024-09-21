/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 21 September 2024
 * Problem 27:  Write a program to receive messages from the message queue.
    a. with 0 as a flag
    b. with IPC_NOWAIT as a flag
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<time.h>
#include<errno.h>
#include<string.h>

#define BUFSIZE 128

struct msg_buffer
{
    int mtype;
    char mtext[BUFSIZE];
};


int main(int argc, char *argv[])
{
    int msqid;
    key_t key;
    struct msg_buffer rcvbuffer;
    int flag = IPC_NOWAIT;

    if(argc < 2){
        printf("Usage: %s filepath",argv[0]);
        exit(0);
    }

    if(argc > 2)
        flag=0;

    key = ftok(argv[1], 65);  
    if (key == -1) {
        perror("ftok");
        exit(0);
    }

    if ((msqid = msgget(key, 0666)) < 0){
        perror("msgget");
        exit(1);
    }

    //Receive an answer of message type 1.
    if (msgrcv(msqid, &rcvbuffer, BUFSIZ, 0, flag) < 0){
        perror("msgrcv");
        exit(1);
    }

    printf("%s\n", rcvbuffer.mtext);
    exit(0);
}

/* Output: 
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out temp/mynod_file
Hello there
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out temp/mynod_file
Hello from the other side
*/