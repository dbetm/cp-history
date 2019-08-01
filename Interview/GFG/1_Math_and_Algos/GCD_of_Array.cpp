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

int main() {
	fastIO();
    int t;
    int n, gcd;
    cin >> t;
    while(t--) {
        cin >> n;
        gcd = INT_MAX;
        int actual, anterior;
        cin >> anterior;
        for (int i = 1; i < n; i++) {
            cin >> actual;
            int aux = __gcd(actual, anterior);
            gcd = min(aux, gcd);
        }
        if(n > 1) cout << gcd << endl;
        else cout << anterior << endl;
    }
	return 0;
}
