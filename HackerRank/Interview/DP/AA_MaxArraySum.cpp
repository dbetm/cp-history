#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/max-array-sum/problem
// Tag(s): DP
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int maxSubsetSum(vector<int> &arr, int i, int dp[]) {
    int ans = 0;
    int n = arr.size();

    if(i >= n) return ans;
    if(dp[i] != -1) return dp[i];

    ans = max(
        arr[i] + maxSubsetSum(arr, i+2, dp),
        maxSubsetSum(arr, i+1, dp)
    );

    return dp[i] = ans;
}

int main() {
    fastIO
    int n;
    cin >> n;
    vector<int> arr(n);
    int dp[n];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxSubsetSum(arr, 0, dp) << endl;

	return 0;
}
