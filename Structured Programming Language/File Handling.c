#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;
    char str[100];
    
    // Writing to a file
    fp = fopen("example.txt", "w");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "Hello, this is a file handling example.\n");
    fprintf(fp, "Second line of text.\n");
    fclose(fp);
    
    // Reading from a file
    fp = fopen("example.txt", "r");
    printf("File contents:\n");
    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
    
    // Binary file operations
    int numbers[5] = {10, 20, 30, 40, 50};
    
    // Write binary
    fp = fopen("data.bin", "wb");
    fwrite(numbers, sizeof(int), 5, fp);
    fclose(fp);
    
    // Read binary
    int read_numbers[5];
    fp = fopen("data.bin", "rb");
    fread(read_numbers, sizeof(int), 5, fp);
    fclose(fp);
    
    printf("\nBinary file read: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", read_numbers[i]);
    }
    printf("\n");
    
    return 0;
}
