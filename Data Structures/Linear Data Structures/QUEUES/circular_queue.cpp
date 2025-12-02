#include <iostream>
using namespace std;

const int MAX = 5;
int cqueue[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % MAX == front;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }
    
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    cqueue[rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return -1;
    }
    
    int value = cqueue[front];
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    
    return value;
}

int peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return cqueue[front];
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    
    cout << "Circular Queue: ";
    int i = front;
    while (true) {
        cout << cqueue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    
    display();
    
    cout << "Front element: " << peek() << endl;
    
    cout << "Dequeued: " << dequeue() << endl;
    cout << "Dequeued: " << dequeue() << endl;
    
    display();
    
    enqueue(60);
    enqueue(70);
    
    display();
    
    return 0;
}
