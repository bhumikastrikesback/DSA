#include <bits/stdc++.h>
using namespace std;

void bestFirstSearch(int start, int goal,
                     vector<vector<int>>& graph,
                     vector<int>& h) {

    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({h[start], start});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int u = cur.second;

        if (visited[u]) continue;
        visited[u] = true;

        cout << "Visited node: " << u << endl;

        if (u == goal)
            break;

        for (int v : graph[u]) {
            if (!visited[v]) {
                pq.push({h[v], v});
                parent[v] = u;
            }
        }
    }

    // Path reconstruction
    cout << "\nPath: ";
    int node = goal;
    while (node != -1) {
        cout << node << " ";
        node = parent[node];
    }
    cout << endl;
}

int main() {
    int n = 5;
    
    //graph(adjencey list)
    vector<vector<int>> graph(n);
    graph[0] = {1,2};
    graph[1] = {3};
    graph[2] = {3};
    graph[3] = {4};
    graph[4] = {};

    //heustic value for each node
    vector<int> h = {7, 6, 2, 1, 0};

    int start = 0;
    int goal = 4;

    bestFirstSearch(start, goal, graph, h);

    return 0;
}