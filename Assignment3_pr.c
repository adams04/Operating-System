#include <stdio.h>
#include <stdlib.h>

void exitHandler1() {
    printf("Exit Handler 1, which is executed.\n");
}

void exitHandler2() {
    printf("Exit Handler 2, which is executed.\n");
}

int main() {
    atexit(exitHandler1);
    atexit(exitHandler2);

    printf("Main function is running yet.\n");

    exit(0);

    printf("This will not be printed.\n");

    return 0;
}

//atexit() helps make sure that important clean-up tasks are done when a program ends.
// This can include closing files or freeing up memory, which helps prevent problems and keeps things running smoothly.

