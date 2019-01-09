#include <bits/stdc++.h>

using namespace std;
// Prototipo de la función
int buscaVecinos(int, int);
// Declaración de variables globales
vector < vector < int > > A; // matriz
int R, C;

int main() {
    int aux, T, g, vecinos, familias = 0, total = 0;
    cin >> T >> g;
    cin >> R >> C;

    for(int i = 0; i < R; i++){
        vector < int > fila;
        for(int j = 0; j < C; j++) {
            cin >> aux;
            if(aux != 1) fila.push_back(0);
            else fila.push_back(1);
        }
        A.push_back(fila);
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << A[i][j] << " ";
            if(A[i][j] == 1) {
                vecinos = buscaVecinos(i, j);
                if(vecinos >= T) {
                    familias++;
                    total += (vecinos - T) * g;
                }
            }
        }
        cout << endl;
    }
    cout << "Núm familias: " << familias << endl;
    cout << "Total: " << total << endl;
    return 0;
}

int buscaVecinos(int i, int j) {
    int ans = 0;
    if(A[i][j] == 1) {
        A[i][j] = 0;
        ans++;
        // derecha iquierda, abajo y arriba
        if(j + 1 < C && A[i][j+1] == 1) ans += buscaVecinos(i, j+1);
        if(j - 1 >= 0 && A[i][j-1] == 1) ans += buscaVecinos(i, j-1);
        if(i + 1 < R && A[i+1][j] == 1)  ans += buscaVecinos(i+1, j);
        if(i - 1 >= 0 && A[i-1][j] == 1) ans += buscaVecinos(i-1, j);
    }
    return ans;
}
