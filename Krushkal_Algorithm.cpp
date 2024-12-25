#include <iostream>
using namespace std;

const int MAX = 100;      // Maximum number of vertices
const int MAX_EDGES = 100; // Maximum number of edges

int parent[MAX];  // Parent array for union-find
int rankArray[MAX]; // Rank array for union-find

// Structure to represent an edge
struct Edge {
    int u, v, weight;  // u and v are the two vertices, weight is the edge weight
};

// Array of edges
Edge edges[MAX_EDGES] = {
    {0, 1, 10}, 
    {0, 2, 6}, 
    {0, 3, 5}, 
    {1, 3, 15}, 
    {2, 3, 4}
}; // Hardcoded edges

int numVertices = 4; // Number of vertices
int numEdges = 5;    // Number of edges

// Function to initialize the union-find data structure
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;      // Each element is its own parent
        rankArray[i] = 0;   // Initialize rank to 0
    }
}

// Function to find the root of the set containing x (with path compression)
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Function to unite two sets (union by rank)
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rankArray[rootX] > rankArray[rootY]) {
            parent[rootY] = rootX;
        } else if (rankArray[rootX] < rankArray[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rankArray[rootX]++;
        }
    }
}

void sortEdges(Edge edges[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                // Use the swap function
                swap(edges[j], edges[j + 1]);
            }
        }
    }
}

// Function to perform Kruskal's algorithm
void kruskal(int n, int m) {
    makeSet(n);  // Initialize the disjoint sets
    sortEdges(edges, m);  // Sort edges by weight

    int mstWeight = 0;  // Total weight of the MST

    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Check if adding this edge creates a cycle
        if (find(u) != find(v)) {
            cout << u << " -- " << v << " == " << weight << endl;
            mstWeight += weight;
            unionSets(u, v);  // Merge the sets
        }
    }

    cout << "Total weight of MST: " << mstWeight << endl;
}

// Main function
int main() {
    // Run Kruskal's algorithm with the hardcoded graph
    kruskal(numVertices, numEdges);

    return 0;
}
