#include <iostream>
using namespace std;

const int MAX = 100;
int stack[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return stack[top];
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    
    display();
    
    cout << "Top element: " << peek() << endl;
    
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    
    display();
    
    return 0;
}
