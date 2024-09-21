/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 21 September 2024
 * Problem 32:  Write a program to implement semaphore to protect any critical section.
    a. rewrite the ticket number creation program using semaphore
    b. protect shared memory from concurrent write access
    c. protect multiple pseudo resources ( may be two) using counting semaphore
    d. remove the created semaphore
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

//Create and init binary semaphore
int create_semaphore(key_t key, int initial_value) {
    int sem_id;
    union semun sem_opt;

    sem_id = semget(key, 1, 0666 | IPC_CREAT);
    if (sem_id == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    sem_opt.val = initial_value;
    if (semctl(sem_id, 0, SETVAL, sem_opt) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    return sem_id;
}

//Decrement the semaphore
void semaphore_wait(int sem_id) {
    struct sembuf sb = {0, -1, 0};  
    if (semop(sem_id, &sb, 1) == -1) {
        perror("semop (wait)");
        exit(EXIT_FAILURE);
    }
}

//Increment the semaphore
void semaphore_signal(int sem_id) {
    struct sembuf sb = {0, 1, 0}; 
    if (semop(sem_id, &sb, 1) == -1) {
        perror("semop (signal)");
        exit(EXIT_FAILURE);
    }
}

// Remove the semaphore
void remove_semaphore(int sem_id) {
    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        perror("semctl (remove)");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore removed.\n");
}

// Critical section: create ticket
void create_ticket(int sem_id) {
    static int ticket_number = 0;  

    semaphore_wait(sem_id);  
    ticket_number++;

    printf("Ticket number generated: %d\n", ticket_number);

    semaphore_signal(sem_id);
}

int main() {
    key_t key;
    int sem_id;
    int i;
    pid_t pid;

    char *sem_path = "temp/sem_log";

    // Generate a unique key for the semaphore
    key = ftok(sem_path, 65);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }


    // Create tickets for multiple processes
    for (i = 0; i < 3; i++) {
        sem_id = create_semaphore(key, 1);
        create_ticket(sem_id); 
    }

    remove_semaphore(sem_id);

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % gcc 32.c
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
Ticket number generated: 1
Ticket number generated: 2
Ticket number generated: 3
Semaphore removed.
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % 
 */