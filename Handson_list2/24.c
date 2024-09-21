#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    key_t key;
    int msgid;

    if(argc < 2){
        printf("Usage: %s filepath",argv[0]);
        exit(0);
    }

    // Generate a unique key using ftok
    key = ftok(argv[1], 65); 
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a message queue with r/w permissions
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Print the key and message queue ID
    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out temp/fifopipe 
Message Queue Key: 1090831797
Message Queue ID: 65536
 */