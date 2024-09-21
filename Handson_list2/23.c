#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
    struct rlimit limit;
    int pipe_fd[2];

    //Max no. of open files
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
    printf("Maximum number of open files per process: %llu\n", limit.rlim_cur);

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Check if F_GETPIPE_SZ exists
#ifdef F_GETPIPE_SZ

    int pipe_size = fcntl(pipe_fd[0], F_GETPIPE_SZ);
    if (pipe_size == -1) {
        perror("fcntl");
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        exit(EXIT_FAILURE);
    }
    printf("Size of the pipe (circular buffer): %d bytes\n", pipe_size);
#else
    printf("F_GETPIPE_SZ not supported on this platform.\n");
#endif

    close(pipe_fd[0]);
    close(pipe_fd[1]);

    return 0;
}

/* Output:
Maximum number of open files per process: 1048575
F_GETPIPE_SZ not supported on this platform.
 */