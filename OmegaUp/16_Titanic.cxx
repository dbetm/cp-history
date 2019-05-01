#include <bits/stdc++.h>
// O(n * m) TC
// https://omegaup.com/arena/problem/Titanic#problems
using namespace std;
int buscarVecinos(int, int);

int mapa[1000][1000];
int n;
int m;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int sobrevivientes = 0;
    cin >> n >> m;
    char c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if(c == '#') mapa[i][j] = 1;
        }
    }

    // exploración
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(mapa[i])
                if(buscarVecinos(i, j) == 1) sobrevivientes++;

    cout << sobrevivientes << "\n";
    return 0;
}

int buscarVecinos(int i, int j) {
    int ans = 0;
    if(mapa[i][j]) {
        mapa[i][j] = 0;
        ans++;
        // derecha iquierda, abajo y arriba
        if(j + 1 < m && mapa[i][j+1] == 1) ans += buscarVecinos(i, j+1);
        if(j - 1 >= 0 && mapa[i][j-1] == 1) ans += buscarVecinos(i, j-1);
        if(i + 1 < n && mapa[i+1][j] == 1)  ans += buscarVecinos(i+1, j);
        if(i - 1 >= 0 && mapa[i-1][j] == 1) ans += buscarVecinos(i-1, j);
    }
    return ans;
}
