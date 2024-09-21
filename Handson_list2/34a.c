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
#include <sys/wait.h>
#include <signal.h>

#define PORT 6066
#define BUFFER_SIZE 1024

void sigchld_handler(int s) {
    while (waitpid(-1, NULL, WNOHANG) > 0); //wait for any child proc to complete
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    const char *hello = "Hello from server";

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

    signal(SIGCHLD, sigchld_handler);

    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();
        if (pid == 0) {  
            close(server_fd);  
            read(new_socket, buffer, BUFFER_SIZE);
            printf("Client: %s\n", buffer);
            printf("Server instance on pid: %d\n",getpid());
            send(new_socket, hello, strlen(hello), 0);
            printf("Hello message sent to client\n");
            close(new_socket); 
            exit(0);
        } else if (pid > 0) {  
            close(new_socket);  
        } else {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./b.out
Server listening on port 6066
Client: Hello from client
Server instance on pid: 30141
Hello message sent to client
Client: Hello from client
Server instance on pid: 30153
Hello message sent to client
Client: Hello from client
Server instance on pid: 30169
Hello message sent to client
*/