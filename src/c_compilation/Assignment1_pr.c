#include <stdio.h>
#include <unistd.h>

int main() {
    
    pid_t id = fork();

     if (id == 0) {
        printf("Child Process: PID = %d\n", getpid());
        return 0;
    } else if(id > 0) {
        printf("Parent Process: PID = %d\n", getpid());
        return 0;
    }
}

