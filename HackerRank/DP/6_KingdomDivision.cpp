#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

map<int, vector<int>> lista;

int main() {
	fastIO
    int n, u, v, cont, tam;
    cin >> n;

    while(cin >> u >> v) {
        lista[u].push_back(v);
        lista[v].push_back(u);
    }

    bool dom[n+1];
    memset(dom, false, sizeof(dom));

    int64_t tabla[n+1];
    memset(tabla, 0, sizeof(tabla));
    tabla[0] = 1;


    for (int i = 1; i <= n; i++) {
        dom[i] = true;
        cont = 0;
        tam = lista[i].size();
        //watch(tam)
        for (int j = 0; j < tam; j++) {
            if(dom[lista[i][j]]) cont++;
        }
        tabla[i] = (tabla[i-1] % MAX + cont % MAX) % MAX;
    }

    cout << (tabla[n] % MAX) << endl;

	return 0;
}
