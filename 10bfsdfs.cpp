#include <iostream>
using namespace std;

int cost[10][10], adjList[10][10], visited[10], qu[10], front = 0, rear = 0, node, edge;

// Simple DFS using adjacency matrix
void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;
    for (int i = 0; i < node; i++) {
        if (cost[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// Simple BFS using adjacency list
void BFS(int v) {
    visited[v] = 1;
    qu[rear++] = v; // Add initial vertex to queue
    cout << v << " ";
    
    while (front < rear) {
        int current = qu[front++]; // Dequeue the element
        for (int i = 0; i < node; i++) {
            if (adjList[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                qu[rear++] = i; // Enqueue adjacent vertex
                cout << i << " ";
            }
        }
    }
}

int main() {
    // Take number of vertices and edges as input
    cout << "Enter number of vertices : ";
    cin >> node;
    cout << "Enter number of edges : ";
    cin >> edge;

    // Initialize adjacency matrix and list
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cost[i][j] = 0;  // Initially, no edges in the graph
            adjList[i][j] = 0;  // Initialize adjacency list
        }
    }

    // Input edges and update adjacency matrix and list
    cout << "\nEnter edges (u v):\n";
    for (int k = 0; k < edge; k++) {
        int u, v;
        cin >> u >> v;
        cost[u][v] = 1;
        cost[v][u] = 1;  // Since the graph is undirected

        adjList[u][v] = 1; // Add edge in adjacency list
        adjList[v][u] = 1; // Add reverse edge for undirected graph
    }

    // Display the adjacency matrix
    cout << "The adjacency matrix of the graph is:\n";
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }

    // Display the adjacency list
    cout << "\nThe adjacency list of the graph is:\n";
    for (int i = 0; i < node; i++) {
        cout << "Vertex " << i << " : ";
        for (int j = 0; j < node; j++) {
            if (adjList[i][j] == 1) {
                cout << " -> " << j;
            }
        }
        cout << endl;
    }

    // Perform DFS
    cout << "\nEnter initial vertex for DFS: ";
    int startVertex;
    cin >> startVertex;

    cout << "DFS traversal of the graph is:\n";
    for (int i = 0; i < node; i++) visited[i] = 0;  // Reset visited array for DFS
    DFS(startVertex);
    cout << endl;

    // Perform BFS
    cout << "\nEnter initial vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS traversal of the graph is:\n";
    for (int i = 0; i < node; i++) visited[i] = 0;  // Reset visited array for BFS
    BFS(startVertex);
    cout << endl;

    return 0;
}
