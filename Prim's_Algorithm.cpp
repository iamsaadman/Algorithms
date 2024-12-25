#include <iostream>

using namespace std;

#define V 5 // Number of vertices

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int parent[V];      // To store the MST
    int min_weight[V];  // Minimum edge weights
    int visited[V];     // To track visited vertices

    // Initialize all vertices as unvisited and keys to a large value
    for (int i = 0; i < V; i++) {
        min_weight[i] = 100;  // Arbitrarily large value to start
        visited[i] = 0;       // Mark all vertices as unvisited
        parent[i] = -1;       // Initialize parent array
    }

    min_weight[0] = 0; // Start from the first vertex
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = -1; // Initialize u as -1

        // Find the unvisited vertex with the smallest key
        for (int v = 0; v < V; v++) {
            // Check if vertex v is unvisited and if it's the smallest
            if (visited[v] == 0) {
                if (u == -1 || min_weight[v] < min_weight[u]) {
                    u = v; // Update u to the new vertex
                }
            }
        }

        visited[u] = 1; // Mark this vertex as visited

        // Update the key and parent for adjacent vertices
        for (int v = 0; v < V; v++) {
            // Check if there is an edge from u to v and if v is unvisited
            if (graph[u][v] != 0 && visited[v] == 0) {
                // Check if the current edge is smaller than the previously recorded weight
                if (graph[u][v] < min_weight[v]) {
                    parent[v] = u;         // Update parent
                    min_weight[v] = graph[u][v]; // Update the minimum weight
                }
            }
        }
    }

    // Print the edges of the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }

    return 0;
}
