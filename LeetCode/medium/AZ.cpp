#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <climits>
// https://leetcode.com/problems/coin-change/
// Tag(s): DP, recursion
#define watch(x) cout << (#x) << " es " << x << endl;

using namespace std;

class Solution {
public:
    int compute(vector<int> &coins, int amount, vector<int> &dp) {
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX, n = coins.size();

        for (int i = 0; i < n; i++) {
            if((amount - coins[i]) >= 0) {
                int subAns = compute(coins, amount-coins[i], dp);
                if(subAns != INT_MAX and subAns < ans) {
                    ans = 1 + subAns;
                }
            }
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int> &coins, int amount, vector<int> &dp) {
        int ans = compute(coins, amount, dp);
        if(ans == INT_MAX) return -1;

        return ans;
    }
};

int main() {
    int n, amount;
    Solution sol;

    cin >> n;
    vector<int> coins(n);
    vector<int> dp(amount + 1, -1);

    for (int i = 0; i < n; ++i) cin >> coins[i];
    cin >> amount;

    cout << "Min # of coins is: " << sol.coinChange(coins, amount, dp) << endl;

    return 0;
}
