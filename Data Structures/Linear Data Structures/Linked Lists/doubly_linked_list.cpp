#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Create new node
DNode* createDNode(int value) {
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(DNode* &head, int value) {
    DNode* newNode = createDNode(value);
    
    if(head == nullptr) {
        head = newNode;
        return;
    }
    
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(DNode* &head, int value) {
    DNode* newNode = createDNode(value);
    
    if(head == nullptr) {
        head = newNode;
        return;
    }
    
    DNode* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after a given node
void insertAfter(DNode* node, int value) {
    if(node == nullptr) {
        cout << "Node cannot be null\n";
        return;
    }
    
    DNode* newNode = createDNode(value);
    newNode->next = node->next;
    newNode->prev = node;
    
    if(node->next != nullptr) {
        node->next->prev = newNode;
    }
    node->next = newNode;
}

// Delete node by value
void deleteNode(DNode* &head, int value) {
    if(head == nullptr) return;
    
    DNode* temp = head;
    
    // Find node to delete
    while(temp != nullptr && temp->data != value) {
        temp = temp->next;
    }
    
    // If value not found
    if(temp == nullptr) {
        cout << value << " not found\n";
        return;
    }
    
    // If node to delete is head
    if(temp == head) {
        head = temp->next;
        if(head != nullptr) {
            head->prev = nullptr;
        }
    } else {
        if(temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if(temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
    }
    
    delete temp;
}

// Display forward
void displayForward(DNode* head) {
    DNode* temp = head;
    cout << "Forward: ";
    while(temp != nullptr) {
        cout << temp->data;
        if(temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Display backward
void displayBackward(DNode* head) {
    if(head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    
    // Go to last node
    DNode* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    
    cout << "Backward: ";
    while(temp != nullptr) {
        cout << temp->data;
        if(temp->prev != nullptr) {
            cout << " <-> ";
        }
        temp = temp->prev;
    }
    cout << " -> NULL\n";
}

// Reverse doubly linked list
void reverseList(DNode* &head) {
    if(head == nullptr || head->next == nullptr) return;
    
    DNode* curr = head;
    DNode* temp = nullptr;
    
    while(curr != nullptr) {
        // Swap prev and next pointers
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        
        // Move to next node
        curr = curr->prev;
    }
    
    // Update head
    if(temp != nullptr) {
        head = temp->prev;
    }
}

// Free memory
void deleteList(DNode* &head) {
    DNode* curr = head;
    while(curr != nullptr) {
        DNode* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

int main() {
    DNode* head = nullptr;
    
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);
    insertAtEnd(head, 30);
    
    cout << "Original list:\n";
    displayForward(head);
    displayBackward(head);
    
    // Insert after node with value 20
    DNode* temp = head;
    while(temp != nullptr && temp->data != 20) {
        temp = temp->next;
    }
    if(temp != nullptr) {
        insertAfter(temp, 25);
        cout << "\nAfter inserting 25 after 20:\n";
        displayForward(head);
        displayBackward(head);
    }
    
    deleteNode(head, 20);
    cout << "\nAfter deleting 20:\n";
    displayForward(head);
    
    reverseList(head);
    cout << "\nAfter reversal:\n";
    displayForward(head);
    displayBackward(head);
    
    deleteList(head);
    
    return 0;
}
