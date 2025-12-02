#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    struct StackNode* temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack (top to bottom): ");
    struct StackNode* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(5);
    push(10);
    push(15);
    push(20);
    
    display();
    
    printf("Top element: %d\n", peek());
    
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    
    display();
    
    return 0;
}
