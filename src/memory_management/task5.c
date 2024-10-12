#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the grades: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int max = array[0], min = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }

    printf("Highest grade: %d\n", max);
    printf("Lowest grade: %d\n", min);

    free(array);

    return 0;
}

