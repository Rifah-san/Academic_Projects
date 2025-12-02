#include <iostream>
using namespace std;

class ArrayOperations {
private:
    int* arr;
    int size;
    int capacity;
    
public:
    ArrayOperations(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }
    
    ~ArrayOperations() {
        delete[] arr;
    }
    
    // Insert at position
    void insert(int index, int value) {
        if (size >= capacity) {
            cout << "Array overflow\n";
            return;
        }
        if (index < 0 || index > size) {
            cout << "Invalid index\n";
            return;
        }
        
        for (int i = size; i > index; i--) {
            arr[i] = arr[i-1];
        }
        arr[index] = value;
        size++;
    }
    
    // Delete element
    void deleteElement(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return;
        }
        
        for (int i = index; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }
    
    // Search element
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) return i;
        }
        return -1;
    }
    
    // Update element
    void update(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return;
        }
        arr[index] = value;
    }
    
    // Display array
    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    // Reverse array
    void reverse() {
        for (int i = 0; i < size/2; i++) {
            swap(arr[i], arr[size-i-1]);
        }
    }
    
    // Rotate array
    void rotate(int k) {
        k = k % size;
        int* temp = new int[k];
        
        // Store first k elements
        for (int i = 0; i < k; i++) {
            temp[i] = arr[i];
        }
        
        // Shift remaining elements
        for (int i = 0; i < size - k; i++) {
            arr[i] = arr[i + k];
        }
        
        // Place stored elements at end
        for (int i = 0; i < k; i++) {
            arr[size - k + i] = temp[i];
        }
        
        delete[] temp;
    }
};

int main() {
    ArrayOperations arr(10);
    
    arr.insert(0, 10);
    arr.insert(1, 20);
    arr.insert(2, 30);
    arr.insert(3, 40);
    arr.insert(4, 50);
    
    arr.display();
    
    arr.deleteElement(2);
    arr.display();
    
    cout << "Search 40: Index = " << arr.search(40) << endl;
    
    arr.update(1, 25);
    arr.display();
    
    arr.reverse();
    cout << "After reverse: ";
    arr.display();
    
    arr.rotate(2);
    cout << "After rotating by 2: ";
    arr.display();
    
    return 0;
}
