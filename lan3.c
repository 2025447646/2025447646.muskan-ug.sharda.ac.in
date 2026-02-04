#include<stdio.h>

// Factorial nikalne ka function
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int n, r, choice;
    long long result;

    printf("Permutation and Combination Calculator\n");
    printf("1. Permutation (nPr)\n");
    printf("2. Combination (nCr)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Enter value of r: ");
    scanf("%d", &r);

    if (choice == 1) {
        // nPr = n! / (n-r)!
        result = factorial(n) / factorial(n - r);
        printf("Permutation (nPr) is: %lld\n", result);
    } 
    else if (choice == 2) {
        // nCr = n! / (r! * (n-r)!)
        result = factorial(n) / (factorial(r) * factorial(n - r));
        printf("Combination (nCr) is: %lld\n", result);
    } 
    else {
        printf("Invalid choice!\n");
    }

    return 0; // Function end
}