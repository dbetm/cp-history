#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Cardinalidad-de-un-conjunto#problems
using namespace std;
typedef long long int lli;
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n, m, numero;
    cin >> n >> m;
    set<int> numeros;
    char accion;
    while(m--) {
        cin >> accion;
        if(accion == 'I') {
            cin >> numero;
            numeros.insert(numero);
        }
        else if(accion == 'C') {
            cout << numeros.size() << endl;
        }
        else {
            cin >> numero;
            numeros.erase(numero);
        }
    }
    return 0;
}
