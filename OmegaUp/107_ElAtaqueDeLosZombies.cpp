#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/El-ataque-de-los-zombies#problems
using namespace std;

typedef long long int lli;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, vida;
    lli sumaAtaque, total;
    lli dps[31];
    while(cin >> n) {
        sumaAtaque = 0;
        total = 0;
        // Daños por segundo
        for (int i = 0; i < n; i++) {
            cin >> dps[i];
            sumaAtaque += dps[i];
        }
        // Puntos de vida
        for (int i = 0; i < n; i++) {
            cin >> vida;
            total += sumaAtaque * vida;
            sumaAtaque -= dps[i];
        }
        cout << total << endl;
    }

    return 0;
}
