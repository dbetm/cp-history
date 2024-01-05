#include <bits/stdc++.h>
// No pasó
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
    lli n, m, num;
    cin >> n >> m;
    lli oponentes[n];
    for (int i = 0; i < n; i++) {
        cin >> num;
        oponentes[i] = (i >= m) ? num : 0;
    }
    lli sol = 0;
    for (int i = m; i < n; i++) {
        lli aux = 0;
        for (int j = i+m, x = 0; x < m && j < n; j++, x++) {
            aux = max(aux, oponentes[j]);
        }
        oponentes[i] = max(oponentes[i-1], oponentes[i] + aux);
    }
    sol = oponentes[n-1];
    cout << sol << endl;
	return 0;
}
