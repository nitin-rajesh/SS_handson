#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6066

int main(int argc, char *argv[]) {
    //TCP server
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFSIZ] = {0};

    const char *server_msg = "Hello from server";

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

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    read(new_socket, buffer, BUFSIZ);
    printf("Client: %s\n", buffer);

    // Send a response to the client
    send(new_socket, server_msg, strlen(server_msg), 0);
    printf("Hello message sent to client\n");

    // Close the socket
    close(new_socket);
    close(server_fd);

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./b.out 
Server listening on port 6066
Client: Hello from client
Hello message sent to client
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % 
*/