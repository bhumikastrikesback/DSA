#include <bits/stdc++.h>
using namespace std;

// DFS function
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;      
    cout << node << " ";         
    // explore all neighbors (choices)
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);  // recursion
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);  // adjacency list (1-based indexing)
    vector<bool> visited(n + 1, false);

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    int startNode;
    cout << "Enter starting node: ";
    cin >> startNode;

    cout << "DFS Order: ";
    dfs(startNode, adj, visited);  // start DFS from startNode
    cout << endl;

    return 0;
}