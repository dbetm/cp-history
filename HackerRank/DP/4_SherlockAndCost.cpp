#include <bits/stdc++.h>
// No está bien :/
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
lli tabla[10001][101];

lli getMaxS(int b[], int n, int lim);

int main() {
	fastIO
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int b[n];
        memset(tabla, -1, sizeof(tabla));
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
		cout << getMaxS(b, n-1, b[n-1]) << endl;
    }
	return 0;
}

lli getMaxS(int b[], int n, int lim) {
	// Caso base
	if(n == 0) return tabla[0][lim] = b[n];
	else if(tabla[n][lim] != -1) return tabla[n][lim];
	else if(n == 1) {
		return tabla[1][lim] = abs(b[1] - b[0]);
	}
	lli ans = 0;
	for (int i = 1; i <= lim; i++) {
		ans = max(ans + abs(b[n] - b[n-1]), getMaxS(b, n-1, i));
	}
	if(n-1 >= 0) ans += getMaxS(b, n-1, b[n-1]);

	return tabla[n][lim] = ans;
}
