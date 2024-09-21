/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 17 September 2024
 * Problem 7: Write a simple program to print the created thread ids.
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// Thread function that will be executed by each thread
void* thread_function(void* arg){
    int thread_id = *((int*)arg);  // Extract the thread ID
    printf("Thread ID %d is running.\n", thread_id);
    pthread_exit(NULL);  // Terminate the thread
}

int main(){
    pthread_t threads[3]; 
    int thread_args[3]; 
    
    for (int i = 0; i < 3; i++) {
        thread_args[i] = i + 1;  // Thread IDs 1, 2, 3
        int result = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args[i]);
        if (result != 0) {
            printf("Error creating thread %d\n", i + 1);
            exit(1);
        }
    }

    for (int i = 0; i < 3; i++) 
        pthread_join(threads[i], NULL);


    printf("Threads complete.\n");

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 
Thread ID 3 is running.
Thread ID 2 is running.
Thread ID 1 is running.
Threads complete.
*/