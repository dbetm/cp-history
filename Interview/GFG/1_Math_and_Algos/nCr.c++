#include <bits/stdc++.h>
// No aceptado
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 10e9 + 7;

lli combinatory(int64_t n, int64_t r);

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

lli combinatory(int64_t n, int64_t k) {
    uint64_t res = 1;
    // Al ver el triángulo de pascal vemos que n-ésima línea es simétrica
    // entonces podemos hacer menos cálculos si k > n-k
    if(k > (n-k)) k = n-k;

    // Calculamos
    // bc(n,k) = [n * (n-1) * ... * (n-k+1)] / [k * (k-1) * ... * 1]
    for (int64_t i = 0; i < k; i++) {
        res = ((res % MAX) * (n - i)) % MAX;
        res /= (i + 1);
    }
    return (res % MAX);
}
