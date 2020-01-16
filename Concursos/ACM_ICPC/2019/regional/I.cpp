#include <bits/stdc++.h>
// https://matcomgrader.com/problem/9643/improve-spam/
// Tag(s): Implementation, dp, recursion
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
vector<vector<lli>> vertices;
unordered_set<lli> visitados;
lli dp[2001];
lli l;

lli dfs(int n);

int main() {
	fastIO
    lli n, k, adr, ll;
    cin >> n >> l;
    ll = l;
    while(ll--) {
        cin >> k;
        vector<lli> lista;
        while(k--) {
            cin >> adr;
            lista.push_back(adr-1);
        }
        vertices.push_back(lista);
    }

    dfs(0);

    cout << (dp[0]%MAX) << " " << (int)visitados.size() << endl;

	return 0;
}

lli dfs(int n) {
    lli msj = 0;
    //watch(n)
    //cin.get();
    //watch(dp[n])
    if(dp[n] != 0) {
        return dp[n];
    }
    else {
        int tam = vertices[n].size();
        for (int i = 0; i < tam; i++) {
            //watch(vertices[n][i])
            if(vertices[n][i] < l) { // es lista
                msj = (msj + dfs(vertices[n][i])) % MAX;
            }
            // dirección de correo
            else {
                msj = (msj + 1) % MAX;
                visitados.insert(vertices[n][i]);
            }
        }
    }

    return dp[n] = msj;
}
