#include <bits/stdc++.h>
//
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

int main() {
    fastIO
    int n, m, a, b;
    cin >> n >> m;
    lli arr[n+1] = {0}, k, aux;
    uint64_t hip = 0, delta;

    while(m--) {
        cin >> a >> b >> k;
        arr[a] += k;
        if(b+1 <= n) arr[b+1] -= k;
    }

    delta = arr[1];
    hip = arr[1];
    for (int i = 2; i <= n; i++) {
        aux = arr[i];
        arr[i] += delta;
        delta = aux;
        if(arr[i] > hip) {
            hip = arr[i];
        }
    }

    cout << hip << endl;

	return 0;
}
