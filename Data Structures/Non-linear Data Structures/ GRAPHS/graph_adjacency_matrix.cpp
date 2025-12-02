#include <iostream>
using namespace std;

const int MAX = 100;
int adjMatrix[MAX][MAX];
int vertices;

void createGraph() {
    cout << "Enter number of vertices: ";
    cin >> vertices;
    
    // Initialize matrix with 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    
    int edges, u, v;
    cout << "Enter number of edges: ";
    cin >> edges;
    
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }
}

void displayMatrix() {
    cout << "\nAdjacency Matrix:\n  ";
    for (int i = 0; i < vertices; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    for (int i = 0; i < vertices; i++) {
        cout << i << " ";
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = -1, rear = -1;
    
    visited[start] = 1;
    queue[++rear] = start;
    
    cout << "BFS starting from vertex " << start << ": ";
    
    while (front != rear) {
        int current = queue[++front];
        cout << current << " ";
        
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    cout << endl;
}

void DFS(int start, int visited[]) {
    cout << start << " ";
    visited[start] = 1;
    
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[start][i] == 1 && !visited[i]) {
            DFS(i, visited);
        }
    }
}

int main() {
    createGraph();
    displayMatrix();
    
    int start;
    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;
    BFS(start);
    
    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;
    int visited[MAX] = {0};
    cout << "DFS starting from vertex " << start << ": ";
    DFS(start, visited);
    cout << endl;
    
    return 0;
}
