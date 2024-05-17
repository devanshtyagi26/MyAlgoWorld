#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int> dfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> v1;
    stack<int> s;
    bool visited[n] = {false};

    s.push(0);
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        if (!visited[node]) {
            visited[node] = true;
            v1.push_back(node);

            // Push all adjacent nodes to the stack
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                if (!visited[adj[node][i]]) {
                    s.push(adj[node][i]);
                }
            }
        }
    }
    return v1;
}

int main() {
    int n = 6; // Number of vertices
    vector<vector<int>> adj = {
        {1, 2},     // Adjacency list for vertex 0
        {0, 3, 4},  // Adjacency list for vertex 1
        {0, 4},     // Adjacency list for vertex 2
        {1, 5},     // Adjacency list for vertex 3
        {1, 2},     // Adjacency list for vertex 4
        {3}         // Adjacency list for vertex 5
    };

    // Perform DFS traversal
    vector<int> dfs_result = dfsTraversal(n, adj);

    // Output DFS traversal result
    cout << "DFS Traversal: ";
    for (int i = 0; i < dfs_result.size(); i++) {
        cout << dfs_result[i] << " ";
    }
    cout << endl;

    return 0;
}
