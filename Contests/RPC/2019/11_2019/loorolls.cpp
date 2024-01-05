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

lli greatestCommonDivisor(lli a, lli b) {
    return b ? greatestCommonDivisor(b, a % b) : a;
}

// ...
lli lcm(lli a, lli b) {
    return (a * b) / greatestCommonDivisor(a, b);
}

int main() {
	fastIO
    lli l, n;
    cin >> l >> n;
    lli aux = lcm(l, n);
    cout << (((aux/2) / l)+1) << endl;
	return 0;
}
