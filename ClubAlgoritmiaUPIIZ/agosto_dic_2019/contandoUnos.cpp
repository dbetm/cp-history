#include <bits/stdc++.h>

using namespace std;
#define MAX 101
// Variables globales
int matriz[MAX][MAX];
int r, c;
// Prototipos de funciones
void leerMatriz();
int buscarVecinos(int i, int j);

int main() {
    leerMatriz();
    int familias = 0, vecinos;
    // Exploramos desde cada posición de la matriz
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(matriz[i][j] == 1) {
                familias++;
                vecinos = buscarVecinos(i, j);
                cout << "La familia " << familias;
                cout << " tiene " << vecinos << " vecinos." << endl;
            }
        }
    }
    cout << "En total hay " << familias << " familia(s) de unos" << endl;
    return 0;
}

void leerMatriz() {
    cout << "Escribe el número de filas: ";
    cin >> r;
    cout << "Escribe el número de columnas: ";
    cin >> c;
    cout << "Escribe los valores de la matriz: " << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> matriz[i][j];
    }
}

int buscarVecinos(int i, int j) {
    int total = 0;
    // Caso base, encontrar un 0
    if(matriz[i][j] == 0) total += 0; // no tiene mucho sentido
    else {
        matriz[i][j] = 0; // actualizamos, marcar territorio explorado
        total++;
        // ### Exploramos en 4 direcciones (si es posible) ###
        // Arriba
        if(i-1 >= 0 && matriz[i-1][j] == 1) total += buscarVecinos(i-1, j);
        // Abajo
        if(i+1 < r && matriz[i+1][j] == 1)  total += buscarVecinos(i+1, j);
        // Izquierda
        if(j-1 >= 0 && matriz[i][j-1] == 1) total += buscarVecinos(i, j-1);
        // Derecha
        if(j+1 < c && matriz[i][j+1] == 1)  total += buscarVecinos(i, j+1);
    }

    return total;
}
