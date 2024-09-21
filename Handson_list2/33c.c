#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6066

int main(int argc, char *argv[]) {
    int socket_id = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZ] = {0};
    const char *hello = "Hello from client";

    if(argc < 2){
        printf("Usage: %s <server_ip>",argv[0]);
        exit(0);
    }

    if ((socket_id = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(socket_id, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(socket_id, hello, strlen(hello), 0);
    printf("Hello message sent to server\n");

    read(socket_id, buffer, BUFSIZ);
    printf("Server: %s\n", buffer);

    close(socket_id);

    return 0;
}

/* Output:
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % ./a.out 127.0.0.1
Hello message sent to server
Server: Hello from server
nitinrajesh@Nitins-MacBook-Pro Handson_list2 % 
*/