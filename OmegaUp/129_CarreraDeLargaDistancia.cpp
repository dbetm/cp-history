#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Carrera-de-Larga-Distancia#problems
using namespace std;

int main() {
    int m, t, u, f, d;
    cin >> m >> t >> u >> f >> d;
    char c;
    int i;
    for (i = 0; i < t; i++) {
        cin >> c;
        if(c == 'U' || c == 'D') {
            if((m - u - d) < 0) break;
            else m -= (u + d);
        }
        else if(c == 'F') {
            if((m - 2*f) < 0) break;
            else m -= 2*f;
        }
    }
    cout << i << endl;

    for (int j = i+1; j < t; j++) {
        cin >> c;
    }

    return 0;
}
