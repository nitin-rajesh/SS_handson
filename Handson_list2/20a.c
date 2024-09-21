#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char FIFO_IN[] = "temp/myfifo";

int main() {
    int fd_in;
    char buffer[128];

    fd_in = open(FIFO_IN, O_RDONLY);
    if (fd_in == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(fd_in, buffer, sizeof(buffer));

    printf("Received message: %s", buffer);

    close(fd_in);

    unlink(FIFO_IN);

    return 0;
}

/* Output:
Received message: Hello from Mario!
 */