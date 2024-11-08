#include <bits/stdc++.h>
// https://leetcode.com/problems/edit-distance/
// Tag(s): DP
using namespace std;

#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define watch(x) cout << (#x) << " is " << x << endl;

int getMinOpsEditDistance(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    /*
    match => dp[i][j] = dp[i-1][j-1];
    mismatch => min(insert, delete, replace)
        insert = dp[i][j-1]
        delete = dp[i-1][j]
        replace = dp[i-1][j-1]
    */
    // Base cases
    int dp[2][n+1];
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        int currentRow = i % 2;
        int prevRow = (i-1) % 2;

        dp[currentRow][0] = i; // base case

        for (int j = 1; j <= n; ++j) {
            if(s1[i-1] == s2[j-1]) {
                dp[currentRow][j] = dp[prevRow][j-1];
            }
            else {
                int insert = dp[currentRow][j-1];
                int del = dp[prevRow][j];
                int replace = dp[prevRow][j-1];

                dp[currentRow][j] = 1 + min(insert, min(del, replace));
            }
        }
    }

    return dp[m % 2][n];
}

int main() {
    fastIO
    string s1, s2;
    cin >> s1;
    cin >> s2;

    cout << getMinOpsEditDistance(s1, s2) << endl;

    return 0;
}
