#include <iostream>
#include <vector>
#include <iomanip>  // For controlling output format
#include <climits>  // Required for INT_MAX to represent infinity

using namespace std;

#define INF INT_MAX  // Define INF as the largest possible integer, representing no direct path

// Function to create a distance matrix from the adjacency matrix
vector<vector<int>> createDistanceMatrix(vector<vector<int>> A, int n) {
    vector<vector<int>> D(n, vector<int>(n, 0));  // Initialize the distance matrix with zeros

    // Loop through all pairs of nodes (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                D[i][j] = 0;  // Distance to itself is 0
            else if (A[i][j] == 0)
                D[i][j] = INF;  // No direct edge (represented as 0), set distance to infinity
            else
                D[i][j] = A[i][j];  // Direct distance from node i to node j
        }
    }
    return D;  // Return the newly created distance matrix
}

// Floyd-Warshall algorithm to find shortest paths
vector<vector<int>> floydWarshall(vector<vector<int>> A) {
    int n = A.size();  // Number of vertices in the graph
    vector<vector<int>> D = createDistanceMatrix(A, n);  // Initialize the distance matrix

    // Triple nested loop to update distances considering each node k as an intermediate node
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check if there's a valid path through k (i.e., no overflow/INF)
                if (D[i][k] < INF && D[k][j] < INF)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);  // Update the shortest path if found
            }
        }
    }

    return D;  // Return the final shortest path matrix
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));  // Create an adjacency matrix of size n x n
    cout << "\nEnter the adjacency matrix (0 if no direct edge):\n";
    
    // Input the adjacency matrix where A[i][j] represents the distance from vertex i to vertex j
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Distance from vertex " << i << " to vertex " << j << ": ";
            cin >> A[i][j];
        }
    }

    // Apply Floyd-Warshall to compute shortest paths
    vector<vector<int>> D = floydWarshall(A);

    cout << "\nShortest distances between all pairs of vertices:\n";

    // Print the shortest distances matrix in a formatted way
    for (int i = 0; i < D.size(); i++) {
        for (int j = 0; j < D.size(); j++) {
            if (D[i][j] == INF)
                cout << setw(7) << "INF";  // If distance is infinity, print "INF"
            else
                cout << setw(7) << D[i][j];  // Otherwise, print the actual distance
        }
        cout << endl;
    }

    return 0;  // End the program
}




#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of nodes:";
    cin>>n;
    
    vector<vector<int>>adjMatrix(n,vector<int>(n));
    
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                adjMatrix[i][j]=0;
            }else{
                int weight;
                cout<<"Weight from node "<<i+1<<"to node"<<j+1<<":";
                cin>>weight;
                adjMatrix[i][j]=(weight==0) ? INT_MAX:weight;
        }
    }
    }
    for(int k=0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adjMatrix[i][k]!=INT_MAX && adjMatrix[k][j]!=INT_MAX){
                    adjMatrix[i][j] = min(adjMatrix[i][j],adjMatrix[i][k]+adjMatrix[k][j]);
                }
            }
        }
    }
    cout<<"Shortest path:\n";
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(adjMatrix[i][j]==INT_MAX)
                cout<<"INF";
            else
                cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
