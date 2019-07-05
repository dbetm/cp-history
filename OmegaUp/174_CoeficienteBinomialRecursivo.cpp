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

lli coefficientBinomial(lli n, lli k) {
    if(n == k || k == 0) {
        return 1;
    }
    else {
        return coefficientBinomial(n-1, k-1) + coefficientBinomial(n-1, k);
    }
}

int main() {
	fastIO();
    lli n, k;
    cin >> n >> k;
    int64_t ans = coefficientBinomial(n, k);
    int64_t cont = ans;
    if(!(n & 1)) cont++;
    cout << ans << " " << cont << endl;
	return 0;
}
