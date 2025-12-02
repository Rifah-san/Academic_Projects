#include <stdio.h>
#include <string.h>

int main() {
    // 1D Array
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Array elements: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 2D Array
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("2D Array:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Strings
    char str1[20] = "Hello";
    char str2[20] = "World";
    
    // String functions
    printf("Length of str1: %lu\n", strlen(str1));
    strcat(str1, " ");
    strcat(str1, str2);
    printf("Concatenated: %s\n", str1);
    
    // String comparison
    if(strcmp("Hello", "Hello") == 0) {
        printf("Strings are equal\n");
    }
    
    return 0;
}
