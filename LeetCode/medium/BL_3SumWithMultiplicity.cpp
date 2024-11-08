#include <bits/stdc++.h>
// https://leetcode.com/problems/3sum-with-multiplicity/
// Tag(s): Math, arrays
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
const lli M = 1e9+7;

/* Brute Force, TLE
int threeSumMulti(vector<int>& arr, int target) {
    int n = arr.size();
    int ans = 0, i, j, k;

    for (i = 0; i < n; ++i) {
        for (j = i+1; j < n; ++j) {
            for (k = j+1; k < n; ++k) {
                if(target == (arr[i] + arr[j] + arr[k])) {
                    ans = (ans + 1) % M;
                }
            }
        }
    }

    return ans % M;
}
*/

/* Use a map to count all the sums of two numbers until arr[i] */
int threeSumMulti(vector<int> & arr, int target) {
    int n = arr.size(), ans = 0;
    unordered_map<int, int> allSums;

    for (int i = 0; i < n; ++i) {
        ans = (ans + allSums[target - arr[i]]) % M;

        for (int j = 0; j < i; ++j) {
            allSums[arr[i] + arr[j]]++;
        }
    }

    return ans % M;
}

int main() {
    fastIO
    int n, target;
    cin >> n;
    vi arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];
    cin >> target;

    cout << threeSumMulti(arr, target) << endl;

	return 0;
}
