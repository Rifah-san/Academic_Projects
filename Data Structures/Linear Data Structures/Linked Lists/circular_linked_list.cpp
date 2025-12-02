#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

// Create new node
CNode* createCNode(int value) {
    CNode* newNode = new CNode;
    newNode->data = value;
    newNode->next = newNode; // Points to itself initially
    return newNode;
}

// Insert at beginning
void insertAtBeginning(CNode* &last, int value) {
    CNode* newNode = createCNode(value);
    
    if(last == nullptr) {
        last = newNode;
        return;
    }
    
    newNode->next = last->next;
    last->next = newNode;
}

// Insert at end
void insertAtEnd(CNode* &last, int value) {
    CNode* newNode = createCNode(value);
    
    if(last == nullptr) {
        last = newNode;
        return;
    }
    
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

// Display circular list
void displayList(CNode* last) {
    if(last == nullptr) {
        cout << "List is empty\n";
        return;
    }
    
    CNode* temp = last->next;
    cout << "Circular List: ";
    
    do {
        cout << temp->data;
        if(temp->next != last->next) {
            cout << " -> ";
        }
        temp = temp->next;
    } while(temp != last->next);
    
    cout << " (back to " << last->next->data << ")\n";
}

// Delete node by value
void deleteNode(CNode* &last, int value) {
    if(last == nullptr) return;
    
    CNode* curr = last->next;
    CNode* prev = last;
    
    // If only one node
    if(curr == last && curr->data == value) {
        delete curr;
        last = nullptr;
        return;
    }
    
    // If head node to be deleted
    if(curr->data == value) {
        last->next = curr->next;
        delete curr;
        return;
    }
    
    // Search for node
    do {
        prev = curr;
        curr = curr->next;
    } while(curr != last->next && curr->data != value);
    
    // If found
    if(curr->data == value) {
        prev->next = curr->next;
        
        // If last node is being deleted
        if(curr == last) {
            last = prev;
        }
        
        delete curr;
    } else {
        cout << value << " not found\n";
    }
}

// Check if list is circular
bool isCircular(CNode* head) {
    if(head == nullptr) return true;
    
    CNode* slow = head;
    CNode* fast = head;
    
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) return true;
    }
    
    return false;
}

// Count nodes
int countNodes(CNode* last) {
    if(last == nullptr) return 0;
    
    int count = 0;
    CNode* temp = last->next;
    
    do {
        count++;
        temp = temp->next;
    } while(temp != last->next);
    
    return count;
}

// Free memory
void deleteList(CNode* &last) {
    if(last == nullptr) return;
    
    CNode* curr = last->next;
    CNode* start = last->next;
    
    do {
        CNode* next = curr->next;
        delete curr;
        curr = next;
    } while(curr != start);
    
    last = nullptr;
}

int main() {
    CNode* last = nullptr;
    
    insertAtEnd(last, 10);
    insertAtEnd(last, 20);
    insertAtBeginning(last, 5);
    insertAtEnd(last, 30);
    
    cout << "Original list:\n";
    displayList(last);
    cout << "Number of nodes: " << countNodes(last) << endl;
    
    deleteNode(last, 20);
    cout << "\nAfter deleting 20:\n";
    displayList(last);
    
    deleteNode(last, 5);
    cout << "\nAfter deleting 5:\n";
    displayList(last);
    
    deleteList(last);
    
    return 0;
}
