#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child Process: PID = %d\n", getpid());
        exit(0);
    } else if (pid > 0) {
        printf("Parent Process: PID = %d, Child Process: PID = %d\n", getpid(), pid);
        wait(NULL);
        printf("Parent process has waited for the child, preventing a zombie.\n");
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}

