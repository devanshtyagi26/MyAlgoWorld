#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Class to represent Disjoint Set Union (DSU) data structure
class disjointSets {
  vector<int> rank, parent; // Arrays to store rank and parent of each node

public:
  // Constructor to initialize DSU for 'n' nodes
  disjointSets(int n) {
    rank.resize(n + 1, 0); // Initialize rank of each node to 0
    parent.resize(n + 1);  // Initialize parent array
    for (int i = 0; i <= n; i++) {
      parent[i] = i; // Each node is its own parent (self-loop initially)
    }
  }

  // Function to find the ultimate parent of a node using path compression
  int findParent(int node) {
    if (node == parent[node]) {
      return node; // If node is its own parent, return it
    }
    return parent[node] = findParent(parent[node]); // Path compression
  }

  // Function to perform union of two sets based on rank
  void unionByRank(int u, int v) {
    int ult_Par_u = findParent(u); // Find ultimate parent of node u
    int ult_Par_v = findParent(v); // Find ultimate parent of node v

    if (ult_Par_u == ult_Par_v) {
      return; // If both nodes have the same parent, they are already in the
              // same set
    }

    // Union by rank
    if (rank[ult_Par_u] < rank[ult_Par_v]) {
      parent[ult_Par_u] =
          ult_Par_v; // Attach the smaller rank tree under the larger one
    } else if (rank[ult_Par_v] < rank[ult_Par_u]) {
      parent[ult_Par_v] = ult_Par_u;
    } else {
      parent[ult_Par_v] =
          ult_Par_u;     // If ranks are the same, attach one to the other
      rank[ult_Par_u]++; // Increment the rank of the new root
    }
  }
};

// Comparison function to sort edges by weight
bool cpm(vector<int> &a, vector<int> &b) { return a[2] < b[2]; }

// Function to find the Minimum Spanning Tree (MST) using Kruskal's Algorithm
int minimumSpanningTree(vector<vector<int>> &edges, int n) {
  // Sort all edges by weight (ascending order)
  sort(edges.begin(), edges.end());

  // Initialize Disjoint Set Union (DSU) for 'n' nodes
  disjointSets ds(n);

  int minWeight = 0; // Variable to store the total weight of the MST

  // Iterate through all edges
  for (int i = 0; i < edges.size(); i++) {
    int u = ds.findParent(
        edges[i][1]); // Find parent of the first vertex of the edge
    int v = ds.findParent(
        edges[i][2]);     // Find parent of the second vertex of the edge
    int wt = edges[i][0]; // Weight of the current edge

    // If the nodes u and v are in different sets, add the edge to the MST
    if (u != v) {
      minWeight += wt;      // Add weight of the edge to the MST total weight
      ds.unionByRank(u, v); // Union the two sets
    }
  }
  return minWeight; // Return the total weight of the MST
}

int main() {
  // Define a graph with edges in the format {weight, node1, node2}
  vector<vector<int>> edges = {{1, 1, 4}, {2, 1, 2}, {3, 2, 3},
                               {3, 2, 4}, {4, 1, 5}, {5, 3, 4},
                               {7, 2, 6}, {8, 3, 6}, {9, 4, 5}};

  // Call the function and print the result
  cout << "Minimum weight of this Spanning Tree using Kruskal's Algorithm is: "
       << minimumSpanningTree(edges, 9);

  return 0;
}
