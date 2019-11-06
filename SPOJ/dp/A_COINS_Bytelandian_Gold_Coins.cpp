#include <bits/stdc++.h>
// WA
// Tag(s): dp,
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

lli maxAmount(lli n, map<int, lli> &tabla);

int main() {
    fastIO
    lli n;
    while(cin >> n) {
        map<int, lli> tabla;
        cout << (lli)(maxAmount(n, tabla)) << endl;
    }
	return 0;
}

lli maxAmount(lli n,  map<int, lli> &tabla) {
    lli ans = n;

    map<int, lli>::iterator it = tabla.find(n);

    if(it != tabla.end())
        return tabla[n];

    if(n <= 1) {
        tabla.insert(pair<int, lli>(n, 0));
        return tabla[n];
    }
    ans = max(ans, maxAmount(n/2, tabla) + maxAmount(n/3, tabla) + maxAmount(n/4, tabla));
    tabla.insert(pair<int, lli>(n, ans));

    return tabla[n];
}
