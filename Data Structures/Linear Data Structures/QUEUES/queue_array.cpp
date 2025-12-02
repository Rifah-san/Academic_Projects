#include <iostream>
using namespace std;

const int MAX = 100;
int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1 || front > rear;
}

bool isFull() {
    return rear == MAX - 1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }
    
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return -1;
    }
    
    int value = queue[front];
    front++;
    
    if (front > rear) { // Reset queue
        front = rear = -1;
    }
    
    return value;
}

int peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
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
