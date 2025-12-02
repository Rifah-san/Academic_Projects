#include <iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode* next;
};

QueueNode* front = nullptr;
QueueNode* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(int value) {
    QueueNode* newNode = new QueueNode;
    newNode->data = value;
    newNode->next = nullptr;
    
    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }
    
    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return -1;
    }
    
    QueueNode* temp = front;
    int value = temp->data;
    front = front->next;
    
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp;
    return value;
}

int peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return front->data;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    
    cout << "Queue: ";
    QueueNode* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();
    
    cout << "Front element: " << peek() << endl;
    
    cout << "Dequeued: " << dequeue() << endl;
    cout << "Dequeued: " << dequeue() << endl;
    
    display();
    
    return 0;
}
