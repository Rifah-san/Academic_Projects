#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

void createSparseMatrix(Element sparse[], int &sparseCount, int matrix[][5], int rows, int cols) {
    sparseCount = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparse[sparseCount].row = i;
                sparse[sparseCount].col = j;
                sparse[sparseCount].value = matrix[i][j];
                sparseCount++;
            }
        }
    }
}

void displaySparse(Element sparse[], int sparseCount, int rows, int cols) {
    int k = 0;
    cout << "\nSparse Matrix Representation (" << rows << "x" << cols << "):\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(k < sparseCount && sparse[k].row == i && sparse[k].col == j) {
                cout << sparse[k].value << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    
    cout << "\nTriplet Form (row, col, value):\n";
    for(int i = 0; i < sparseCount; i++) {
        cout << "(" << sparse[i].row << ", " << sparse[i].col << ", " << sparse[i].value << ")\n";
    }
}

void transposeSparse(Element sparse[], int sparseCount, Element transposed[], int &transCount) {
    transCount = sparseCount;
    
    // Count elements in each column
    int* colCount = new int[5](); // Assuming max 5 columns
    for(int i = 0; i < sparseCount; i++) {
        colCount[sparse[i].col]++;
    }
    
    // Calculate starting positions
    int* startPos = new int[5];
    startPos[0] = 0;
    for(int i = 1; i < 5; i++) {
        startPos[i] = startPos[i-1] + colCount[i-1];
    }
    
    // Fill transposed matrix
    for(int i = 0; i < sparseCount; i++) {
        int pos = startPos[sparse[i].col];
        transposed[pos].row = sparse[i].col;
        transposed[pos].col = sparse[i].row;
        transposed[pos].value = sparse[i].value;
        startPos[sparse[i].col]++;
    }
    
    delete[] colCount;
    delete[] startPos;
}

int main() {
    const int ROWS = 4, COLS = 5;
    int matrix[ROWS][COLS] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    
    const int MAX_ELEMENTS = 20;
    Element sparse[MAX_ELEMENTS];
    int sparseCount;
    
    createSparseMatrix(sparse, sparseCount, matrix, ROWS, COLS);
    displaySparse(sparse, sparseCount, ROWS, COLS);
    
    Element transposed[MAX_ELEMENTS];
    int transCount;
    transposeSparse(sparse, sparseCount, transposed, transCount);
    
    cout << "\nTransposed Matrix:";
    displaySparse(transposed, transCount, COLS, ROWS);
    
    return 0;
}
