#include<iostream>
using namespace std;

#define SIZE 10 // Max number of nodes supported

int main() {
    int n, i, j;
    int cost[10][10];     // Adjacency matrix to store costs between nodes
    int min;              // To store minimum cost edge in each iteration
    int visit[10];        // Array to track visited nodes
    int s;                // Starting node
    int row, col;         // Store edge endpoints with min cost
    int total = 0;        // Total cost of MST
    int ne = 1;           // Number of edges in MST, initially 1

    cout << "Enter number of nodes==(enter the offices in different cities): ";
    cin >> n;

    // Initially, mark all nodes as unvisited
    for(i = 1; i <= n; i++) {
        visit[i] = 0;
    }

    // Take input for the cost adjacency matrix
    cout << "\nEnter cost adjacency matrix (Enter matrix):\n";
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> cost[i][j];

            // If cost is 0 (no edge), treat it as infinite (999)
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    // Display message before showing MST edges
    cout << "\nEdges of Minimum Spanning Tree:\n";

    // Ask user for starting vertex
    cout << "Enter the starting vertex: ";
    cin >> s;

    // Mark the starting vertex as visited
    visit[s] = 1;

    // Repeat until we get n-1 edges in the MST
    while(ne < n) {
        min = 999; // Reset min edge cost in each iteration

        // Loop through all visited vertices
        for(i = 1; i <= n; i++) {
            if(visit[i] == 1) {
                // Check adjacent vertices to find the minimum cost edge
                for(j = 1; j <= n; j++) {
                    if(cost[i][j] < min && visit[j] == 0) {
                        min = cost[i][j]; // Update minimum
                        row = i;          // Store edge start
                        col = j;          // Store edge end
                    }
                }
            }
        }

        // If a valid edge is found, add it to MST
        if(row != col) {
            ne++; // Increment number of edges in MST
            cout << "\nEdge == " << row << " to " << col << " == " << min;
            visit[row] = visit[col] = 1; // Mark both endpoints as visited
            total += min; // Add edge cost to total
        }
    }

    // Print total cost of the MST
    cout << "\n\nMinimum cost = " << total;
    return 0;
}
