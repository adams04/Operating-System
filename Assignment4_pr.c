#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    pid1 = fork();
    if (pid1 == 0) {
        printf("First Child Process: PID = %d\n", getpid());
        exit(1);
    } else if (pid1 > 0) {
        int status1;
        waitpid(pid1, &status1, 0);
        if (WIFEXITED(status1)) {
            printf("First Child Exit Status: %d\n", WEXITSTATUS(status1));
            printf("First Child Exited Normally.\n");
        } else {
            printf("First Child did not exit normally.\n");
        }
   }
    pid2 = fork();

    if (pid2 == 0) {
        printf("Second Child Process: PID = %d\n", getpid());
        exit(2);
    } else if (pid2 >  0) {
        int status2;
        waitpid(pid2, &status2, 0);
        if (WIFEXITED(status2)) {
            printf("Second Child Exit Status: %d\n", WEXITSTATUS(status2));
            printf("Second Child Exited Normally.\n");
        } else {
            printf("Second Child did not exit normally.\n");
        }
    }
   return 0; 
}
