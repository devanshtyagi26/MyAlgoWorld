#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> v1;
    queue<int> q;
    bool visited[n] = {false};
    
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        v1.push_back(temp);
        for (int i = 0; i < adj[temp].size(); i++) {
            if (!visited[adj[temp][i]]) {
                q.push(adj[temp][i]);
                visited[adj[temp][i]] = true;
            }
        }
    }
    return v1;
}

int main() {
    int n = 6; // Number of vertices
    vector<vector<int>> adj = {
        {2},     // Adjacency list for vertex 0
        {0, 3, 4},  // Adjacency list for vertex 1
        {0, 4},     // Adjacency list for vertex 2
        {1, 5},     // Adjacency list for vertex 3
        {1, 2},     // Adjacency list for vertex 4
        {3}         // Adjacency list for vertex 5
    };

    // Perform BFS traversal
    vector<int> bfs_result = bfsTraversal(n, adj);

    // Output BFS traversal result
    cout << "BFS Traversal: ";
    for (int i = 0; i < bfs_result.size(); i++) {
        cout << bfs_result[i] << " ";
    }
    cout << endl;

    return 0;
}
