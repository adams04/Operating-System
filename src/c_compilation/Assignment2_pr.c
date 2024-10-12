#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

     if (pid == 0) {
        printf("First Child Process: PID = %d\n", getpid());
        return 0;
    } else if (pid > 0) {
        int status1;
        wait(&status1);
        printf("First Child Exit Status: %d\n", WEXITSTATUS(status1));
    }
        
        pid_t pid2 = fork();

        if (pid2 == 0) {
            printf("Second Child Process: PID = %d\n", getpid());
            return 0;
        } else if (pid2 > 0) {
            int status2;
            waitpid(pid2, &status2, 0);
            printf("Second Child Exit Status: %d\n", WEXITSTATUS(status2));
        }

    return 0;
}
