#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<time.h>
#include<errno.h>
#include<string.h>

struct msg_buffer
{
    int mtype;
    char mtext[128];
};

int main(int argc, char *argv[])
{
    int msg_q_id;
    key_t key;
    struct msg_buffer mbuf;

    if(argc < 2){
        printf("Usage: %s filepath",argv[0]);
        exit(0);
    }

    key = ftok(argv[1], 65);  
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    if ((msg_q_id = msgget(key, IPC_CREAT|0666 )) < 0){
        perror("msgget");
        exit(1);
    }   
    
    //Message Type
    mbuf.mtype = 1;

    printf("Enter message to append to queue: ");
    scanf("%[^\n]",mbuf.mtext);
    getchar();

    if (msgsnd(msg_q_id, &mbuf, strlen(mbuf.mtext) + 1, IPC_NOWAIT) < 0)
    {
        perror("msgsnd");
        exit(0);
    }


    printf("--Message Sent--\n");
    printf ("Msg queue ID: %d\nMtype ID: %d\nText: %s\n", 
        msg_q_id, mbuf.mtype, mbuf.mtext);
    
    exit(0);
}

/* Output:

nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out temp/mynod_file 
Enter message to append to queue: Hello there   
--Message Sent--
Msg queue ID: 65539
Mtype ID: 1
Text: Hello there
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ipcs -q
IPC status from <running system> as of Sat Sep 21 11:01:39 IST 2024
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:
q  65536 0x4104c5b5 --rw-rw-rw- nitinrajesh    staff
q  65537 0x4104c74e --rw-rw-rw- nitinrajesh    staff
q  65538 0x41042770 --rw-rw-rw- nitinrajesh    staff
q  65539 0x4104c74d --rw-rw-rw- nitinrajesh    staff 
*/