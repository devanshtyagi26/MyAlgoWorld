#include <iostream>
#include <vector>
using namespace std;

// Class implementing the Bellman-Ford Algorithm
class bellmanFordAlgo {

public:
  // Function to compute the shortest distances using Bellman-Ford
  vector<int> bellmanFord(int v, vector<vector<int>> &edges, int source) {
    // Initialize distance array with maximum values (INT_MAX)
    vector<int> distance(v, INT_MAX);

    // Distance to the source is 0
    distance[source] = 0;

    // Relax all edges v-1 times (where v is the number of vertices)
    for (int i = 0; i < v - 1; i++) {
      for (auto it : edges) {
        int wt = it[0]; // Weight of the edge
        int u = it[1];  // Source vertex of the edge
        int v = it[2];  // Destination vertex of the edge

        // If the current distance to u is not infinity and we find a shorter
        // path to v
        if (distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
          distance[v] = distance[u] + wt; // Update the distance to v
        }
      }
    }

    // Check for negative weight cycles by iterating over all edges one more
    // time
    for (auto it : edges) {
      int wt = it[0]; // Weight of the edge
      int u = it[1];  // Source vertex of the edge
      int v = it[2];  // Destination vertex of the edge

      // If a shorter path is still found, it means there is a negative weight
      // cycle
      if (distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
        return {-1}; // Return {-1} to indicate a negative weight cycle
      }
    }

    // Return the final distances from the source to all vertices
    return distance;
  }
};

int main() {
  bellmanFordAlgo obj; // Create an instance of the Bellman-Ford class

  int v = 5; // Number of vertices
  // Define the edges of the graph: {weight, from, to}
  vector<vector<int>> edges = {{-1, 0, 1}, {4, 0, 2}, {3, 1, 2}, {2, 1, 3},
                               {2, 1, 4},  {5, 3, 2}, {1, 3, 1}, {-3, 4, 3}};

  int source = 0; // Define the source vertex
  vector<int> distances = obj.bellmanFord(v, edges, source);

  // Check for negative weight cycles
  if (distances[0] == -1 && distances.size() == 1) {
    cout << "Negative weight cycle detected." << endl;
  } else {
    // Print the shortest distances from the source to each vertex
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < v; i++) {
      cout << "Vertex " << i << ": " << distances[i] << endl;
    }
  }
  return 0;
}