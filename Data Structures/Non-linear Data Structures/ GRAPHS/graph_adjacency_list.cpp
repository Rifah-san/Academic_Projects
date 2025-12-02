#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

Node* adjList[100];
int vertices;

Node* createNode(int v) {
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = nullptr;
    return newNode;
}

void addEdge(int u, int v) {
    // Add edge from u to v
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    
    // Add edge from v to u (undirected graph)
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void createGraph() {
    cout << "Enter number of vertices: ";
    cin >> vertices;
    
    // Initialize adjacency list
    for (int i = 0; i < vertices; i++) {
        adjList[i] = nullptr;
    }
    
    int edges, u, v;
    cout << "Enter number of edges: ";
    cin >> edges;
    
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        addEdge(u, v);
    }
}

void displayList() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": ";
        Node* temp = adjList[i];
        while (temp != nullptr) {
            cout << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

void BFS(int start) {
    int visited[100] = {0};
    int queue[100], front = -1, rear = -1;
    
    visited[start] = 1;
    queue[++rear] = start;
    
    cout << "BFS starting from vertex " << start << ": ";
    
    while (front != rear) {
        int current = queue[++front];
        cout << current << " ";
        
        Node* temp = adjList[current];
        while (temp != nullptr) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[++rear] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

void DFS(int start, int visited[]) {
    cout << start << " ";
    visited[start] = 1;
    
    Node* temp = adjList[start];
    while (temp != nullptr) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    createGraph();
    displayList();
    
    int start;
    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;
    BFS(start);
    
    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;
    int visited[100] = {0};
    cout << "DFS starting from vertex " << start << ": ";
    DFS(start, visited);
    cout << endl;
    
    return 0;
}
