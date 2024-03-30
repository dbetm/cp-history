#include <bits/stdc++.h>
// https://codeforces.com/gym/102254/problem/B
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
    string a1, a2;
    cin >> a1 >> a2;
    int n = a1.size(), m = a2.size();
    int tabla[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // Caso base
            if(i == 0 || j == 0) tabla[i][j] = 0;
            // Dos casos, son iguales los caracteres
                // Se toma la última solución + 1
            else if(a1[i-1] == a2[j-1]) tabla[i][j] = tabla[i-1][j-1] + 1;
            // No son iguales
                // Se toma el máximo de ignorar alguno de los caracteres
            else tabla[i][j] = max(tabla[i-1][j], tabla[i][j-1]);
        }
    }

    cout << tabla[n][m] << endl;

	return 0;
}
