#include <bits/stdc++.h>
// https://codeforces.com/group/4Drl6UlALp/contest/264649/problem/E
// Tag(s): dp
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
#define M 100000000
int k1, k2;
int tabla[101][101][11][11];

int compute(int n1, int n2, int i, int j) {
    if(tabla[n1][n2][i][j] != -1) return tabla[n1][n2][i][j];
    int res1 = 0, res2 = 0;

    if(n1 + n2 == 0) {
        return 1;
    }

    if(i < k1 && n1 > 0) res1 = compute(n1-1, n2, i+1, 0) % M;
    if(j < k2 && n2 > 0) res2 = compute(n1, n2-1, 0, j+1) % M;

    return tabla[n1][n2][i][j] = (res1 + res2) % M;
}

int main() {
	fastIO
    memset(tabla, -1, sizeof(tabla));
    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    cout << compute(n1, n2, 0, 0) << endl;
	return 0;
}
