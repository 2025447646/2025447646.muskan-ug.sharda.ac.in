#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void menu(int *ch);
void input(int *arr, int *n);
void display(int *arr, int n);
int sum_array(int *arr, int n);
float avg_array(int *arr, int n);
int min_array(int *arr, int n);
int max_array(int *arr, int n);

int main() {
    int data[100], ch, num_element = 0;

    while(1) {
        menu(&ch); // User se choice lene ke liye pointer use kiya
        
        switch(ch) {
            case 1:
                input(data, &num_element);
                break;
            case 2:
                display(data, num_element);
                printf("\nThe sum of array is: %d\n", sum_array(data, num_element));
                break;
            case 3:
                display(data, num_element);
                printf("\nThe average is: %.2f\n", avg_array(data, num_element));
                break;
            case 4:
                display(data, num_element);
                printf("\nThe minimum element is: %d\n", min_array(data, num_element));
                break;
            case 5:
                display(data, num_element);
                printf("\nThe maximum element is: %d\n", max_array(data, num_element));
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid entry! Please try again.\n");
        }
    }
    return 0;
}

// --- Function Definitions ---

void menu(int *ch) {
    printf("\n--- ARRAY OPERATIONS MENU ---");
    printf("\n1. Input Array");
    printf("\n2. Display & Sum");
    printf("\n3. Display & Average");
    printf("\n4. Display & Minimum");
    printf("\n5. Display & Maximum");
    printf("\n6. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", ch);
}

void input(int *arr, int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);
    for(int i = 0; i < *n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", (arr + i)); // Pointer arithmetic
    }
}

void display(int *arr, int n) {
    printf("Array elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}

int sum_array(int *arr, int n) {
    int s = 0;
    for(int i = 0; i < n; i++) s += *(arr + i);
    return s;
}

float avg_array(int *arr, int n) {
    if (n == 0) return 0;
    return (float)sum_array(arr, n) / n;
}

int min_array(int *arr, int n) {
    int min = *arr;
    for(int i = 1; i < n; i++) {
        if(*(arr + i) < min) min = *(arr + i);
    }
    return min;
}

int max_array(int *arr, int n) {
    int max = *arr;
    for(int i = 1; i < n; i++) {
        if(*(arr + i) > max) max = *(arr + i);
    }
    return max;
}