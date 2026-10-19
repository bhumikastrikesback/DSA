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

int longestSubsequence(string & s1, string & s2, int n, int m, vector<vector<int>>& dp) {
    //base case
    if(n == 0 || m == 0) {
        return 0;
    }

    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    if(s1[n-1] == s2[n-1]) {
        return dp[n][m] = 1 + longestSubsequence(s1, s2, n-1, m-1, dp);
    } else {
        return dp[n][m] = max(longestSubsequence(s1, s2, n - 1, m, dp), longestSubsequence(s1, s2, n, m - 1, dp));
    }
}

int main() {
    inputFromFiles();

    string X,Y;
    cin >> X >> Y;
    int n = X.length();
    int m = Y.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < m+1; j++) {
            dp[i][j] = -1;
       }
    }

    cout << longestSubsequence(X, Y, n, m, dp);
    return 0;
}