#include <iostream>
using namespace std;

// Function to display array
void displayArray(int arr[], int n) {
    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insert element at position
void insertElement(int arr[], int &n, int size, int pos, int value) {
    if(n >= size) {
        cout << "Array overflow\n";
        return;
    }
    if(pos < 0 || pos > n) {
        cout << "Invalid position\n";
        return;
    }
    
    // Shift elements to right
    for(int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = value;
    n++;
}

// Delete element at position
void deleteElement(int arr[], int &n, int pos) {
    if(pos < 0 || pos >= n) {
        cout << "Invalid position\n";
        return;
    }
    
    // Shift elements to left
    for(int i = pos; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
}

// Linear search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary search (array must be sorted)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1;
    
    while(low <= high) {
        int mid = low + (high - low)/2;
        
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Reverse array
void reverseArray(int arr[], int n) {
    for(int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

// Rotate array left by k positions
void rotateLeft(int arr[], int n, int k) {
    k = k % n;
    int* temp = new int[k];
    
    // Store first k elements
    for(int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }
    
    // Shift remaining elements
    for(int i = 0; i < n-k; i++) {
        arr[i] = arr[i+k];
    }
    
    // Copy stored elements to end
    for(int i = 0; i < k; i++) {
        arr[n-k+i] = temp[i];
    }
    
    delete[] temp;
}

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {10, 20, 30, 40, 50};
    int n = 5;
    
    displayArray(arr, n);
    
    insertElement(arr, n, SIZE, 2, 25);
    displayArray(arr, n);
    
    deleteElement(arr, n, 3);
    displayArray(arr, n);
    
    int key = 30;
    int index = linearSearch(arr, n, key);
    if(index != -1)
        cout << key << " found at index " << index << endl;
    else
        cout << key << " not found\n";
    
    // Sort array for binary search
    int sortedArr[] = {10, 20, 30, 40, 50, 60};
    int sortedN = 6;
    cout << "Binary search for 40: " << binarySearch(sortedArr, sortedN, 40) << endl;
    
    reverseArray(arr, n);
    cout << "After reversal: ";
    displayArray(arr, n);
    
    rotateLeft(arr, n, 2);
    cout << "After rotating left by 2: ";
    displayArray(arr, n);
    
    return 0;
}
