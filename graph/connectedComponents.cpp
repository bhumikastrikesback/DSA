#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex) {
    // Take action on vertex after entering the vertex
    vis[vertex] = true;
   for(int child : g[vertex]) {
    // take action on child before enetering the child node
    if(vis[child]) {
        continue;
    }
    dfs(child);
    // take action on child after exiting the child node
   }
   // take action on vertex before exiting the vertex

   
}


int main() {
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == true) {
            continue;
        }
        dfs(i);
        count++;
    }

    cout << count << endl;
}