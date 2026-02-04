#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2, i;
    int *arr;

    printf("Enter initial size (n1): ");
    scanf("%d", &n1);

    arr = (int*)malloc(n1 * sizeof(int));

    printf("Enter %d values:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", (arr + i));
    }

    printf("Enter size to expand (n2): ");
    scanf("%d", &n2);

    arr = (int*)realloc(arr, (n1 + n2) * sizeof(int));

    printf("Enter %d new values:\n", n2);
    for (i = n1; i < (n1 + n2); i++) {
        scanf("%d", (arr + i));
    }

    // Pura array print karne ke liye:
    printf("Final array elements: ");
    for (i = 0; i < (n1 + n2); i++) {
        printf("%d ", *(arr + i));
    }

    free(arr); 
    return 0;
}