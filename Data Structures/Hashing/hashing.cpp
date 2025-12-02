#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct HashNode {
    int key;
    int value;
    HashNode* next;
};

HashNode* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = nullptr;
    }
}

void insertChaining(int key, int value) {
    int index = hashFunction(key);
    
    HashNode* newNode = new HashNode;
    newNode->key = key;
    newNode->value = value;
    newNode->next = nullptr;
    
    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        // Chaining: add to the beginning
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int searchChaining(int key) {
    int index = hashFunction(key);
    HashNode* current = hashTable[index];
    
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Not found
}

void displayHashTable() {
    cout << "\nHash Table (Chaining):\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Bucket " << i << ": ";
        HashNode* current = hashTable[i];
        while (current != nullptr) {
            cout << "(" << current->key << "," << current->value << ") -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
}

// Linear Probing
const int LINEAR_SIZE = 10;
int linearTable[LINEAR_SIZE];
int linearFlag[LINEAR_SIZE]; // 0: empty, 1: occupied, 2: deleted

void initLinearTable() {
    for (int i = 0; i < LINEAR_SIZE; i++) {
        linearTable[i] = -1;
        linearFlag[i] = 0;
    }
}

void insertLinearProbing(int key, int value) {
    int index = hashFunction(key);
    int original = index;
    
    while (linearFlag[index] == 1) {
        index = (index + 1) % LINEAR_SIZE;
        if (index == original) {
            cout << "Hash table is full\n";
            return;
        }
    }
    
    linearTable[index] = value;
    linearFlag[index] = 1;
}

int searchLinearProbing(int key) {
    int index = hashFunction(key);
    int original = index;
    
    while (linearFlag[index] != 0) {
        if (linearFlag[index] == 1 && (index == hashFunction(key) || 
            linearTable[index] != -1)) {
            // Check if this is the right bucket
            if (index == hashFunction(key)) {
                return linearTable[index];
            }
        }
        index = (index + 1) % LINEAR_SIZE;
        if (index == original) break;
    }
    return -1;
}

void displayLinearTable() {
    cout << "\nHash Table (Linear Probing):\n";
    for (int i = 0; i < LINEAR_SIZE; i++) {
        cout << "Index " << i << ": ";
        if (linearFlag[i] == 1) {
            cout << linearTable[i];
        } else if (linearFlag[i] == 2) {
            cout << "DELETED";
        } else {
            cout << "EMPTY";
        }
        cout << endl;
    }
}

int main() {
    // Chaining Example
    cout << "=== CHAINING METHOD ===\n";
    initHashTable();
    
    insertChaining(1, 100);
    insertChaining(2, 200);
    insertChaining(11, 1100); // Collision with key 1
    insertChaining(12, 1200); // Collision with key 2
    insertChaining(21, 2100); // Collision with key 1
    
    displayHashTable();
    
    cout << "\nSearch key 11: " << searchChaining(11) << endl;
    cout << "Search key 5: " << searchChaining(5) << endl;
    
    // Linear Probing Example
    cout << "\n=== LINEAR PROBING ===\n";
    initLinearTable();
    
    insertLinearProbing(1, 100);
    insertLinearProbing(2, 200);
    insertLinearProbing(11, 1100);
    insertLinearProbing(12, 1200);
    insertLinearProbing(21, 2100);
    
    displayLinearTable();
    
    cout << "\nSearch key 11: " << searchLinearProbing(11) << endl;
    cout << "Search key 5: " << searchLinearProbing(5) << endl;
    
    return 0;
}
