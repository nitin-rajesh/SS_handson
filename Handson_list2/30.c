#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    key_t key;
    int shmid;
    char *data;
    const int SHM_SIZE = 1024;  // Shared memory size

    if(argc < 2){
        printf("Usage: %s filepath",argv[0]);
        exit(0);
    }

    key = ftok(argv[1], 65);  
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    printf("Shared memory created with ID: %d\n", shmid);

    //a. Attach to the shared memory and write some data
    data = (char *) shmat(shmid, (void *)0, 0);  
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    printf("Writing to shared memory...\n");
    strcpy(data, "Hello there, shared mem space");

    printf("Data in shared memory: %s\n", data);

    printf("\nTrying to attach in read-only mode...\n");
    char *read_only_data = (char *) shmat(shmid, (void *)0, SHM_RDONLY);
    if (read_only_data == (char *)(-1)) {
        perror("shmat (read-only)");
        exit(EXIT_FAILURE);
    }

    //Try to write in read only mode
    // printf("Trying to overwrite shared memory in read-only mode...\n");
    // strcpy(read_only_data, "Rand text");
    // 
    // printf("Data overwritten\n");
    // 

    //b. Detach the shared memory from read-only mode
    if (shmdt(read_only_data) == -1) {
        perror("shmdt (read-only)");
        exit(EXIT_FAILURE);
    }
    printf("Detached from shared memory (read-only mode).\n");

    //c. Detach the shared memory from the read-write mode
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
    printf("Detached from shared memory.\n");

    //d. Remove the shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl (IPC_RMID)");
        exit(EXIT_FAILURE);
    }
    printf("Shared memory removed successfully.\n");

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out temp/mynod_file
Shared memory created with ID: 131072
Writing to shared memory...
Data in shared memory: Hello there, shared mem space

Trying to attach in read-only mode...
Detached from shared memory (read-only mode).
Detached from shared memory.
Shared memory removed successfully.

Output- When writing in read-only mode:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out temp/mynod_file 
Shared memory created with ID: 65536
Writing to shared memory...
Data in shared memory: Hello, this is shared memory!

Trying to attach in read-only mode...
Trying to overwrite shared memory in read-only mode..
 */