#include <iostream>
using namespace std;

struct StackNode {
    int data;
    StackNode* next;
};

StackNode* top = nullptr;

bool isEmpty() {
    return top == nullptr;
}

void push(int value) {
    StackNode* newNode = new StackNode;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    
    StackNode* temp = top;
    int popped = temp->data;
    top = top->next;
    delete temp;
    return popped;
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return top->data;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    
    cout << "Stack (top to bottom): ";
    StackNode* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(5);
    push(10);
    push(15);
    push(20);
    
    display();
    
    cout << "Top element: " << peek() << endl;
    
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    
    display();
    
    return 0;
}
