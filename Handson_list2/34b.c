/* Name: Nitin Kumar Rajesh
 * Reg no: MT2024103
 * Date: 21 September 2024
 * Problem 34:  Write a program to create a concurrent server.
    a. use fork
    b. use pthread_create
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 6066

void* handle_client(void *socket_desc) {
    pthread_t thread_id = pthread_self();
    printf("Server instance on thread: %lu\n", (unsigned long)thread_id);

    int new_socket = *(int*)socket_desc;
    char buffer[BUFSIZ] = {0};
    const char *hello = "Hello from server";

    read(new_socket, buffer, BUFSIZ);
    printf("Client: %s\n", buffer);

    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent to client\n");

    close(new_socket);
    free(socket_desc);
    pthread_exit(NULL);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        int *socket_desc = malloc(sizeof(int));
        *socket_desc = new_socket;

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)socket_desc) != 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }

        pthread_detach(thread_id);
    }

    close(server_fd);
    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./b.out           
Server listening on port 6066
Server instance on thread: 123145565036544
Client: Hello from client
Hello message sent to client
Server instance on thread: 123145565036544
Client: Hello from client
Hello message sent to client
Server instance on thread: 123145565036544
Client: Hello from client
Hello message sent to client
*/