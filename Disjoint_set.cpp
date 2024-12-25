#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of elements
int parent[MAX];     // Array to store the parent of each element
int rankArray[MAX];  // Array to store the rank (or size) of each set

// Function to initialize the disjoint sets
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;      // Initially, each element is its own parent (i.e., it's its own set)
        rankArray[i] = 0;   // The rank of each set is initialized to 0
    }
}

// Function to find the representative (root) of the set that element x belongs to
// Uses path compression to make future queries faster
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Recursively find the root and update parent[x] to root
    }
    return parent[x];
}

// Function to merge (union) the sets that elements x and y belong to
// Uses union by rank to keep the tree flat
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // Attach the smaller tree under the root of the larger tree
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

// Main function
int main() {
    int n = 5; // Let's assume we have 5 elements (0, 1, 2, 3, 4)
    makeSet(n); // Initialize the disjoint sets

    // Perform some union operations
    unionSets(0, 1); // Merge the sets containing 0 and 1
    unionSets(1, 2); // Merge the sets containing 1 and 2

    // Find the representative of each set
    cout << "Find(0): " << find(0) << endl;
    cout << "Find(1): " << find(1) << endl;
    cout << "Find(2): " << find(2) << endl;
    cout << "Find(3): " << find(3) << endl;

    // Perform another union operation
    unionSets(3, 4); // Merge the sets containing 3 and 4

    cout << "Find(4): " << find(4) << endl;

    // Union sets that have already been merged (no change)
    unionSets(2, 4);

    cout << "Find(0): " << find(0) << endl;
    cout << "Find(4): " << find(4) << endl;

    return 0;
}
