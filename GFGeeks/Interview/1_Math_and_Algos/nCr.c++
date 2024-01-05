#include <bits/stdc++.h>
// Aceptado, solución con DP
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
uint64_t MAX = 1e9 + 7;

lli combinatory(int n, int r);

int main() {
	fastIO();
    int t;
    int n, r;
    cin >> t;
    while(t--) {
        cin >> n >> r;
        if(n < r) cout << 0 << endl;
        else cout << combinatory(n, r) << endl;
    }
	return 0;
}

lli combinatory(int n, int k) {
    int64_t C[k+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            C[j] = (C[j]%MAX + C[j-1]%MAX) % MAX;
        }
    }
    return C[k] % MAX;
}
