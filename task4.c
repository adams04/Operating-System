#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    char **array = (char **)malloc(3 * sizeof(char *));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        array[i] = (char *)malloc(50 * sizeof(char));
        if (array[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("Enter 3 strings: ");
    for (i = 0; i < 3; i++) {
        scanf("%s", array[i]);
    }

    array = (char **)realloc(array, 5 * sizeof(char *));
    if (array == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    for (i = 3; i < 5; i++) {
        array[i] = (char *)malloc(50 * sizeof(char));
        if (array[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("Enter 2 more strings: ");
    for (i = 3; i < 5; i++) {
        scanf("%s", array[i]);
    }

    printf("All strings: ");
    for (i = 0; i < 5; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");

    for (i = 0; i < 5; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}

