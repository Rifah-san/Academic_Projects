#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Create new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(Node* &head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(Node* &head, int value) {
    Node* newNode = createNode(value);
    
    if(head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert after a given node
void insertAfter(Node* prevNode, int value) {
    if(prevNode == nullptr) {
        cout << "Previous node cannot be null\n";
        return;
    }
    
    Node* newNode = createNode(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Delete node by value
void deleteNode(Node* &head, int value) {
    if(head == nullptr) return;
    
    // If head node to be deleted
    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    // Search for node to be deleted
    Node* curr = head;
    Node* prev = nullptr;
    
    while(curr != nullptr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
    
    // If value not found
    if(curr == nullptr) {
        cout << value << " not found in list\n";
        return;
    }
    
    // Unlink node
    prev->next = curr->next;
    delete curr;
}

// Search for value
bool searchNode(Node* head, int value) {
    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Reverse linked list
void reverseList(Node* &head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Get length of list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display linked list
void displayList(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while(temp != nullptr) {
        cout << temp->data;
        if(temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Free memory
void deleteList(Node* &head) {
    Node* curr = head;
    while(curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;
    
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);
    insertAtEnd(head, 30);
    
    cout << "Original list:\n";
    displayList(head);
    cout << "Length: " << getLength(head) << endl;
    
    // Insert after node with value 20
    Node* temp = head;
    while(temp != nullptr && temp->data != 20) {
        temp = temp->next;
    }
    if(temp != nullptr) {
        insertAfter(temp, 25);
        cout << "\nAfter inserting 25 after 20:\n";
        displayList(head);
    }
    
    cout << "\nSearch 20: " << (searchNode(head, 20) ? "Found" : "Not found") << endl;
    cout << "Search 100: " << (searchNode(head, 100) ? "Found" : "Not found") << endl;
    
    deleteNode(head, 20);
    cout << "\nAfter deleting 20:\n";
    displayList(head);
    
    reverseList(head);
    cout << "\nAfter reversal:\n";
    displayList(head);
    
    deleteList(head);
    
    return 0;
}
