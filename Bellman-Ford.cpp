#include <iostream>
using namespace std;

#define V 5 // Number of vertices
#define E 8 // Number of edges

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Main function
int main() {
    // Graph representation as an array of edges
    Edge edges[E] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int distance[V]; // Array to store the shortest distances from the source

    // Initialize distances to a large value
    for (int i = 0; i < V; i++) {
        distance[i] = 1000; // Use a large value (like infinity)
    }
    distance[0] = 0; // Starting vertex

    // Relax edges |V| - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            // Update the distance if a shorter path is found
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight; // Relaxation step
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (distance[u] + weight < distance[v]) {
            cout << "Graph contains a negative weight cycle\n";
            return 0;
        }
    }

    // Calculate the sum of minimum path distances
    int sumOfMinimumPaths = 0;
    for (int i = 0; i < V; i++) {
        // Only add valid distances (not infinity)
        if (distance[i] < 1000) {
            sumOfMinimumPaths += distance[i];
        }
    }

    // Print the shortest distances from the source and the sum
    cout << "Vertex \tDistance from Source (0)\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << distance[i] << "\n"; // Show distances
    }
    cout << "Sum of Minimum Path Distances: " << sumOfMinimumPaths << "\n";

    return 0;
}
