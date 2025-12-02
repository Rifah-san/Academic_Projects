#include <stdio.h>

// Function declaration
int add(int a, int b);
void swap(int *a, int *b);
int factorial(int n);

// Global variable example
int global_var = 100;

int main() {
    int x = 5, y = 10;
    
    // Function call by value
    printf("Sum: %d\n", add(x, y));
    
    // Function call by reference
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("After swap: x=%d, y=%d\n", x, y);
    
    // Recursion
    printf("Factorial of 5: %d\n", factorial(5));
    
    return 0;
}

int add(int a, int b) {
    return a + b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n) {
    if(n <= 1) return 1;  // Base case
    return n * factorial(n - 1);  // Recursive call
}
