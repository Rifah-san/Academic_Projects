#include <stdio.h>
#include <stdlib.h>

int main() {
    int var = 20;
    int *ptr;
    
    // Basic pointer operations
    ptr = &var;
    printf("Address of var: %p\n", &var);
    printf("Pointer ptr contains: %p\n", ptr);
    printf("Value of var using pointer: %d\n", *ptr);
    
    // Pointer arithmetic
    int arr[5] = {10, 20, 30, 40, 50};
    int *arr_ptr = arr;
    printf("Third element via pointer: %d\n", *(arr_ptr + 2));
    
    // Dynamic memory allocation
    int *dyn_arr;
    int n = 5;
    
    dyn_arr = (int*)malloc(n * sizeof(int));
    
    if(dyn_arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for(int i = 0; i < n; i++) {
        dyn_arr[i] = i * 10;
    }
    
    printf("Dynamic array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", dyn_arr[i]);
    }
    printf("\n");
    
    // Reallocation
    dyn_arr = (int*)realloc(dyn_arr, 10 * sizeof(int));
    
    // Free memory
    free(dyn_arr);
    
    return 0;
}
