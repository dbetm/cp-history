#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/coin-change/problem?h_r=profile
using namespace std;
typedef long int li;

li getWays(li arr[], li m, li n);

int main() {
    li n, m;
    cin >> n >> m;
    li arr[m];
    for(li i = 0; i < m; i++) cin >> arr[i];
    cout << getWays(arr, m, n) << endl;
    return 0;
}

li getWays(li arr[], li m, li n) {
    // Create table-store
    li table[n+1] = {};
    // Base case
    table[0] = 1;
    // Build the solution
    for (li i = 0; i < m; i++) {
        for (li j = arr[i]; j <= n; j++) {
            table[j] += table[j - arr[i]];
        }
    }

    return table[n];
}
