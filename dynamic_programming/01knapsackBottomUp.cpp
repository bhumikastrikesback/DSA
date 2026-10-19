#include<bits/stdc++.h>
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

int main() {
    inputFromFiles();
    int n,w;
    cin >> n >> w;

    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long> (w + 1));
    for(int currItemCount = 0; currItemCount < n + 1; currItemCount++) {
        for(int currAvlbWeight = 0; currAvlbWeight < (w+1); currAvlbWeight++) {
            // pruning and base case
            if(currItemCount == 0 || currAvlbWeight == 0) {
                dp[currItemCount][currAvlbWeight] = 0;
            } else {
                // compute
                long long ans = LONG_LONG_MIN;
                // pick
                if(wt[currItemCount - 1] <= currAvlbWeight) {
                    long long pickedAns = val[currItemCount - 1] + dp[currItemCount - 1][currAvlbWeight - wt[currItemCount - 1]];
                    ans = max(ans, pickedAns);
                }
                // not picked
                long long notPicked = dp[currItemCount - 1][currAvlbWeight];
                ans = max(ans, notPicked);

                // save
                dp[currItemCount][currAvlbWeight] = ans;
            }
        }
    }

    cout << dp[n][w] << endl;
    
    return 0;
}