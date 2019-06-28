#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Buscando-Parejas#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int h, m, aux;
    cin >> h >> m;
    if(h <= m) {
        for (int i = 0; i < h; i++) {
            cin >> aux;
        }
        for (int i = 0; i < m; i++) {
            cin >> aux;
        }
        cout << "No hay solteros" << endl;
    }
    else {
        int edadMenor = INT_MAX;
        for (int i = 0; i < h; i++) {
            cin >> aux;
            edadMenor = min(edadMenor, aux);
        }
        for (int i = 0; i < m; i++) {
            cin >> aux;
        }
        cout << h-m << " "<< edadMenor << endl;
    }
    return 0;
}
