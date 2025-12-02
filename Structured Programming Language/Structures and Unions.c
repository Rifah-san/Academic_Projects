#include <stdio.h>
#include <string.h>

// Structure definition
struct Student {
    int roll_no;
    char name[50];
    float marks;
};

// Nested structure
struct Address {
    char city[50];
    int pincode;
};

struct Employee {
    int emp_id;
    char emp_name[50];
    struct Address addr;  // Nested structure
};

// Union definition
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    // Structure variable
    struct Student s1;
    s1.roll_no = 101;
    strcpy(s1.name, "John Doe");
    s1.marks = 85.5;
    
    printf("Student: %s, Roll: %d, Marks: %.2f\n", 
           s1.name, s1.roll_no, s1.marks);
    
    // Array of structures
    struct Student students[3] = {
        {101, "Alice", 90.0},
        {102, "Bob", 85.5},
        {103, "Charlie", 88.0}
    };
    
    // Nested structure
    struct Employee emp = {
        1001, "John Smith", {"New York", 10001}
    };
    
    // Union example
    union Data data;
    data.i = 10;
    printf("data.i = %d\n", data.i);
    
    data.f = 220.5;
    printf("data.f = %.2f\n", data.f);
    
    strcpy(data.str, "C Programming");
    printf("data.str = %s\n", data.str);
    
    return 0;
}
