// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define VERTICES 5

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int findMinKeyVertex(int keys[], bool includedInMST[])
{
    int minValue = INT_MAX, minIndex;

    for (int v = 0; v < VERTICES; v++)
        if (!includedInMST[v] && keys[v] < minValue)
            minValue = keys[v], minIndex = v;

    return minIndex;
}

// A utility function to print the
// constructed MST stored in parent[]
void displayMST(int parent[], int graph[VERTICES][VERTICES])
{
    cout << "Edge \tWeight\n";
    int total = 0;
    for (int i = 1; i < VERTICES; i++){
        total += graph[i][parent[i]];
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
    }
    cout << "\nTotal Weight = " << total;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void computePrimMST(int graph[VERTICES][VERTICES])
{
    int parent[VERTICES];     // Array to store constructed MST
    int keys[VERTICES];       // Key values used to pick minimum weight edge in cut
    bool includedInMST[VERTICES]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and MST set as false
    for (int i = 0; i < VERTICES; i++)
        keys[i] = INT_MAX, includedInMST[i] = false;

    // Always include first vertex in MST.
    keys[0] = 0;    // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have VERTICES vertices
    for (int count = 0; count < VERTICES - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = findMinKeyVertex(keys, includedInMST);

        // Add the picked vertex to the MST Set
        includedInMST[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < VERTICES; v++)

            // graph[u][v] is non-zero only for adjacent vertices of u
            // includedInMST[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !includedInMST[v] && graph[u][v] < keys[v])
                parent[v] = u, keys[v] = graph[u][v];
    }

    // Print the constructed MST
    displayMST(parent, graph);
}

// Driver's code
int main()
{
    int graph[VERTICES][VERTICES] = { { 0, 2, 0, 6, 0 },
                                      { 2, 0, 3, 8, 5 },
                                      { 0, 3, 0, 0, 7 },
                                      { 6, 8, 0, 0, 9 },
                                      { 0, 5, 7, 9, 0 } };

    // Print the solution
    computePrimMST(graph);

    return 0;
}

// This code is contributed by rathbhupendra
