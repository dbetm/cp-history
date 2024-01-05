#include <bits/stdc++.h>
//
// Tag(s): lazy propagation, implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
// Sol. con algoritmo Lazy propagation

int main() {
	fastIO
    int n, m, k;
    lli l, r, d;
    cin >> n >> m >> k;
    lli a[n+2][2];
    lli ops[m+2][4];
    //map<int, tuple<lli, lli, lli>> ops;

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
        a[i][1] = 0;
    }

    for (int i = 1; i <= m; i++) {
        cin >> l >> r >> d;
        ops[i][0] = l;
        ops[i][1] = r;
        ops[i][2] = d;
        ops[i][3] = 0; // veces que se aplica
    }

    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        ops[l][3]++;
        int index = min(m+1, (int)r);
        ops[index][3]--;
        // for (int o = l; o <= r; o++) {
        //     a[get<0>(ops[o])][1] += get<2>(ops[o]);
        //     int aux = get<1>(ops[o]);
        //     int index = min(n+1, aux);
        //     a[index][1] -= get<2>(ops[o]);
        // }
    }
    lli acc = 0;
    for (int i = 1; i <= m; i++) {
        if(ops[i][3] >= 0) {
            acc += ops[i][3];
            ops[i][2] *= acc;
            a[ops[i][0]][1] += ops[i][2];
            a[ops[i][1]][1] -= ops[i][2];;
        }
        else {
            ops[i][2] *= acc;
            a[ops[i][0]][1] += ops[i][2];
            a[ops[i][1]][1] -= ops[i][2];
            acc += ops[i][3];
        }
    }

    for (lli i = 1; i <= n+1; i++) {
        cout << a[i][0] << "->" << a[i][1] << endl;
    }

    lli delta = 0;
    for (int i = 1; i <= n; i++) {
        delta += a[i][1];
        cout << (a[i][0] + delta) << " ";
    }
    cout << endl;

	return 0;
}
