#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int create_semaphore(key_t key, int initial_value) {
    int sem_id;
    union semun sem_opt;

    sem_id = semget(key, 1, 0666 | IPC_CREAT);
    if (sem_id == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Initialize the semaphore to the given initial value
    sem_opt.val = initial_value;
    if (semctl(sem_id, 0, SETVAL, sem_opt) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore created with ID: %d and initialized to: %d\n", sem_id, initial_value);
    return sem_id;
}

int main() {
    key_t key;
    int binary_semid, counting_semid;

    char *sem_path = "temp/sem_log";

    // Generate a unique key for the semaphores
    key = ftok(sem_path, 65);  // Ensure "semfile" exists
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // a. Create a binary semaphore, init to 1
    printf("Creating a binary semaphore...\n");
    binary_semid = create_semaphore(key, 1);  // Binary semaphore initialized to 1 (unlocked)

    // b. Create a counting semaphore, init to 5
    printf("Creating a counting semaphore...\n");
    key = ftok(sem_path, 66);  
    counting_semid = create_semaphore(key, 5);

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
Creating a binary semaphore...
Semaphore created with ID: 131072 and initialized to: 1
Creating a counting semaphore...
Semaphore created with ID: 65537 and initialized to: 5
*/