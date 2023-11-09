#include <bits/stdc++.h>

using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;

int main() {
    int n, k, res = 0;
    cin >> n >> k;
    vector <pair<int, int>> datos(n);
    pair<int, int> par;
    for (int i = 0; i < n; i++) {
        cin >> par.first >> par.second;
        datos[i] = par;
    }
    sort(datos.rbegin(), datos.rend());

    for (int i = 0, cont = 0; i < n; i++) {
        // watch(datos[i].first)
        // watch(datos[i].second)
        if(cont < k && datos[i].second == 1) {
            res += datos[i].first;
            cont++;
        }
        else if(datos[i].second == 0) res += datos[i].first;
        else res -= datos[i].first;
    }

    cout << res << endl;

    return 0;
}
