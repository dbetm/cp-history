#include <bits/stdc++.h>
// https://leetcode.com/problems/longest-common-subsequence/
// Tag(s): DP
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int dp[2][n+1];
    int i, j, currentRow, previousRow;

    memset(dp, 0, sizeof(dp));

    for (i = 1; i <= m; ++i) {
        currentRow = i % 2;
        previousRow = (i-1) % 2;
        for (j = 1; j <= n; ++j) {
            if(s1[i-1] == s2[j-1]) dp[currentRow][j] = 1 + dp[previousRow][j-1];
            else dp[currentRow][j] = max(dp[previousRow][j], dp[currentRow][j-1]);
        }
    }

    return dp[m % 2][n];
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << lcs(s1, s2) << endl;

    return 0;
}
