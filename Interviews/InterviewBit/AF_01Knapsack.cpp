#include <bits/stdc++.h>
// https://www.interviewbit.com/problems/0-1-knapsack/
// Tag(s): DP
using namespace std;

int computeMaxProfit(vector<int> &P, vector<int> &W, int c) {
    int n = P.size();

    int dp[2][c+1];

    // base case
    for (int i = 0; i <= c; ++i) dp[0][i] = 0;

    for (int i = 1; i <= n; ++i) {
        int curRow = i % 2;
        int prevRow = (i-1) % 2;

        // base case
        dp[curRow][0] = 0;

        for (int w = 1; w <= c; w++) {
            // case 1: The i-th article has a weight greater than the w-th weight
            if(W[i-1] > w) {
                dp[curRow][w] = dp[prevRow][w];
            }
            else {
                // case 2: Include the i-th article
                int including = P[i-1] + dp[prevRow][w - W[i-1]];
                // case 3: Not include the i-th article
                int excluding = dp[prevRow][w];

                dp[curRow][w] = max(including, excluding);
            }
        }
    }

    return dp[n % 2][c];
}


int main() {
    int n, capacity;
    cin >> n;
    vector<int> P(n), W(n);

    for (int i = 0; i < n; i++) cin >> P[i];
    for (int i = 0; i < n; i++) cin >> W[i];

    cin >> capacity;

    cout << "The maximum profit is: " << computeMaxProfit(P, W, capacity) << endl;

    return 0;
}
