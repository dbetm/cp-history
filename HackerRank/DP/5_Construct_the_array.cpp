#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

uint64_t getPermutation(uint64_t k, uint64_t r) {
    uint64_t ans = 1;

    for (uint64_t i = k; i > k-r; i--) {
        ans *= i;
        ans %= MAX;
    }

    return ans;
}

int main() {
	fastIO
    uint64_t n, k, x, r, res, q;

    cin >> n >> k >> x;

    r = n - 2;
    res = getPermutation(k, r);
    //watch(res)

    res = res - (k/2 + 1);

    //if(n == 3) res--;

    cout << (uint64_t(res % MAX));

	return 0;
}
