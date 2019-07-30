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

int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a % b) : a;
}

int64_t lcm(int64_t a, int64_t b, int64_t _gcd) {
    return (a * b) / _gcd;
}

int main() {
	fastIO();
    int t;
    cin >> t;
    int64_t a, b;
    while(t--) {
        cin >> a >> b;
        int64_t _gcd = gcd(a, b);
        int64_t _lcm = lcm(a, b, _gcd);
        cout << _lcm << " " << _gcd << endl;
    }
	return 0;
}
