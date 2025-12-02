#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        
        // Calculate position using interpolation formula
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        
        if (arr[pos] == key) {
            return pos;
        } else if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int arr1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n1 = 9;
    int key1 = 50;
    
    cout << "Linear Search:\n";
    int result1 = linearSearch(arr1, n1, key1);
    if (result1 != -1) {
        cout << key1 << " found at index " << result1 << endl;
    } else {
        cout << key1 << " not found\n";
    }
    
    cout << "\nBinary Search:\n";
    int result2 = binarySearch(arr1, n1, key1);
    if (result2 != -1) {
        cout << key1 << " found at index " << result2 << endl;
    } else {
        cout << key1 << " not found\n";
    }
    
    cout << "\nInterpolation Search:\n";
    int arr2[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n2 = 15;
    int key2 = 18;
    int result3 = interpolationSearch(arr2, n2, key2);
    if (result3 != -1) {
        cout << key2 << " found at index " << result3 << endl;
    } else {
        cout << key2 << " not found\n";
    }
    
    return 0;
}
