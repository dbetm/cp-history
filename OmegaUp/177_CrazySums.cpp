#include <bits/stdc++.h>
// No :/
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e7+19;
vi vals;
map<int64_t, int64_t> dp;

int64_t count(int64_t n, int k);

int main() {
	fastIO
    int k, aux;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> aux;
        vals.push_back(aux);
    }

    int64_t n;
    cin >> n;

    cout << (count(n, k) % MAX) << endl;

	return 0;
}

int64_t count(int64_t n, int k) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    int64_t sum = 0;

    map<int64_t, int64_t>::const_iterator it = dp.find(n);

    if(it != dp.end()) {
        return dp[n];
    }
    else {
        for (int i = 0; i < k; i++) {
            sum += count(n-vals[i], k) % MAX;
        }
    }
    dp.insert(pair<int64_t, int64_t>(n, sum % MAX));
    return dp[n];
}
