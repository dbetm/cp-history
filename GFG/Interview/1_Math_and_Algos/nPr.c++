#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int64_t getPermutation(int n, int r) {
    int64_t ans = 1;

    for (int i = n; i > n-r; i--) {
        ans *= i;
    }

    return ans;
}

int main() {
	fastIO();
    int t, n, r;
    cin >> t;

    while(t--) {
        cin >> n >> r;
        cout << getPermutation(n, r) << endl;
    }

	return 0;
}
