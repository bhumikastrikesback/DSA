#include <bits/stdc++.h>
using namespace std;

void inputFromFiles() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-result"
    #ifndef ONLINE_JUDGE
        freopen("/home/bhumika0077/bhumi/input.in", "r", stdin);
        freopen("/home/bhumika0077/bhumi/output.out", "w", stdout);
    #endif
    #pragma GCC diagnostic pop
}

// Recursive function 
int knapsack(int W, vector<int>& wt, vector<int>& val, int currItemIdx) {
    // Base case
    if (currItemIdx < 0 || W == 0) {
        return 0;
    }    
    // skip the current weight
    if (wt[currItemIdx] > W) {
        return knapsack(W, wt, val, currItemIdx - 1);
    }

    // Return max of including or excluding the item
    int include = val[currItemIdx] + knapsack(W - wt[currItemIdx], wt, val, currItemIdx - 1);
    int exclude = knapsack(W, wt, val, currItemIdx - 1);

    return max(include, exclude);
}

int main() {
    inputFromFiles();

    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for(int i = 0; i < n; i++) {
        cout << wt[i] << " " << val[i] << endl;
    }

    int maxValue = knapsack(W, wt, val, n - 1);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
