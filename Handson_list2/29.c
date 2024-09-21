/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 21 September 2024
 * Problem 29:  Write a program to remove the message queue.
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

    if(argc < 2){
        printf("Usage: %s filepath",argv[0]);
        exit(0);
    }

    key = ftok(argv[1], 65);  
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get message queue ID
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID");
        exit(EXIT_FAILURE);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out temp/mynod_file 
Enter message to append to queue: Temp message
--Message Sent--
Msg queue ID: 131075
Mtype ID: 1
Text: Temp message
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ipcs -q                
IPC status from <running system> as of Sat Sep 21 15:15:10 IST 2024
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:
q  65536 0x4104c5b5 --rw-rw-rw- nitinrajesh    staff
q  65537 0x4104c74e --rw-rw-rw- nitinrajesh    staff
q  65538 0x41042770 --rw-rw-rw- nitinrajesh    staff
q 131075 0x4104c74d --rw-rw-rw- nitinrajesh    staff

nitinrajesh@Nitins-MacBook-Pro Handson_list2 % gcc 29.c
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out temp/mynod_file 
Message queue removed successfully.
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ipcs -q
IPC status from <running system> as of Sat Sep 21 15:15:27 IST 2024
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:
q  65536 0x4104c5b5 --rw-rw-rw- nitinrajesh    staff
q  65537 0x4104c74e --rw-rw-rw- nitinrajesh    staff
q  65538 0x41042770 --rw-rw-rw- nitinrajesh    staff

nitinrajesh@Nitins-MacBook-Pro Handson_list2 %   
*/