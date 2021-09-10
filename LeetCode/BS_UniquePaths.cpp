#include <iostream>
#include <vector>
#include <algorithm>
// https://leetcode.com/problems/unique-paths/
// Tag(s): DP, maths

/*
In order to optimize time and space complexity, we can think in permutations
(n-1 + m-1)! / (n-1)! * (m-1)!
*/
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

int computeUniquePaths(int m, int n);

int main() {
    int m, n;
    cin >> m >> n;

    cout << computeUniquePaths(m, n) << endl;

    return 0;
}

int computeUniquePaths(int m, int n) {
    int dp[m][n];

    // base cases
    for (int i = 0; i < m; ++i) dp[i][0] = 1;
    for (int j = 1; j < n; ++j) dp[0][j] = 1;

    int ans = 0;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    ans = dp[m-1][n-1];

    return ans;
}
