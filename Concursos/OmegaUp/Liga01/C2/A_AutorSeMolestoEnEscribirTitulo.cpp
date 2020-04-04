#include <bits/stdc++.h>
// Parcialmente correcta
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

lli extendedGCD(lli a, lli b, lli &x, lli &y);


int main() {
    fastIO
    lli x, y, a, m;
    cin >> a >> m;
    lli g = extendedGCD(a, m, x, y);

    if (g != 1) {
        cout << "No" << endl;
    }
    else {
        cout << "Si" << endl;
    }

	return 0;
}

lli extendedGCD(lli a, lli b, lli &x, lli &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    lli x1, y1;
    lli d = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
