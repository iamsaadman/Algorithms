#include <iostream>
using namespace std;

#define V 5 // Number of vertices

int main() {
    // Adjacency matrix of the graph
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int distance[V]; // Shortest distances
    bool visited[V] = {false}; // Visited vertices

    // Initialize distances as a large number
    for (int i = 0; i < V; i++) {
        distance[i] = 1000; // Large value for "infinity"
    }

    distance[0] = 0; // Starting point

    // Main loop for Dijkstra's Algorithm
    for (int count = 0; count < V - 1; count++) {
        int minIndex = -1;
        for (int v = 0; v < V; v++) {
            // Find the unvisited vertex with the smallest distance
            if (!visited[v] && (minIndex == -1 || distance[v] < distance[minIndex])) {
                minIndex = v; // Update minIndex
            }
        }

        visited[minIndex] = true; // Mark the vertex as visited

        // Update distances for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[minIndex][v] != 0 && !visited[v]) {
                int newDistance = distance[minIndex] + graph[minIndex][v];
                if (newDistance < distance[v]) {
                    distance[v] = newDistance; // Update distance
                }
            }
        }
    }

    // Print results
    cout << "Vertex \tDistance from Source (0)\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << distance[i] << "\n"; // Show distances
    }

    return 0;
}
