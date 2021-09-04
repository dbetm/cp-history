#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
//
// Tag(s):
#define watch(x) cout << (#x) << " es " << x << endl;

using namespace std;

class Solution {
public:
    int coinchange(vector<int> &coins, int amount) {
        int ans = 0;
        int n = coins.size();

        if(amount == 0) return 0;

        sort(coins.rbegin(), coins.rend());

        for (int i = 0; i < n; ++i) {
            int factor = amount / coins[i];
            watch(coins[i])
            watch(factor)
            if(factor < 1) continue;

            ans += factor;
            //int res = amount % (factor * coins[i]);
            amount -= (factor * coins[i]);
            //amount += res;

            if(amount == 0) break;
        }

        if(amount != 0) ans = -1;

        return ans;
    }
};

int main() {
    int n, amount;
    Solution sol;

    cin >> n;
    vector<int> coins(n);

    for (int i = 0; i < n; ++i) cin >> coins[i];
    cin >> amount;

    cout << "The min number of coins is: " << sol.coinchange(coins, amount) << endl;

    return 0;
}
