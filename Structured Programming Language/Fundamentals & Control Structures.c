#include <stdio.h>

int main() {
    // Variables and basic I/O
    int num1 = 10, num2 = 20;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // If-else example
    if(num1 > num2) {
        printf("%d is greater\n", num1);
    } else if(num2 > num1) {
        printf("%d is greater\n", num2);
    } else {
        printf("Both are equal\n");
    }
    
    // Switch case
    char grade = 'B';
    switch(grade) {
        case 'A': printf("Excellent!\n"); break;
        case 'B': printf("Well done\n"); break;
        case 'C': printf("Passed\n"); break;
        default: printf("Invalid grade\n");
    }
    
    // Loops
    printf("For loop: ");
    for(int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
