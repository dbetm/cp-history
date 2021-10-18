#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/candies/problem
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

int getIncre(vector<int> &a) {
    int ans = 0, n = a.size();

    for (int i = 1; i < n; ++i) {
        if(a[i-1] <= a[i]) ++ans;
    }

    return ans;
}

long candies(int n, vector<int> &a) {
    int numInc = getIncre(a);
    int candies[n];
    candies[0] = 1;

    if(numInc < int(n / 2)) reverse(a.begin(), a.end());

    for (int i = 1; i < n; ++i) {
        if(a[i-1] < a[i]) candies[i] = candies[i-1] + 1;
        else if(a[i-1] == a[i]) candies[i] = 1;
        else {
            candies[i] = 1;
            int j = i;
            int x = i-1;

            while(x >= 0 and a[x] > a[j] and candies[x] <= candies[j]) {
                candies[x]++;
                --x;
                --j;
            }
        }
    }

    long ans = 0;
    for (int i = 0; i < n; ++i) ans += candies[i];

    return ans;
}

int main() {
    fastIO
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];

    long ans = candies(n, arr);
    cout << ans << endl;

	return 0;
}
