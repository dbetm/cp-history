#include <bits/stdc++.h>
/*
    Fecha: 23/10/2018
    Descripción: Se trata de encontrar la máxima suma que se puede hacer sobre
    un triángulo, permitiendo sumas en diagonal derecha ^ vertical.
*/
using namespace std;

int A[100][100] = {};

int f(int i, int j, int n) {
    if(i == n || j == n) return 0;
    return max(A[i][j] + f(i+1, j, n), A[i][j] + f(i+1, j+1, n));
}

int main() {
    //int t; // Para el número de casos
    int n;
    cin >> n;
    // Se leen los elementos del triángulo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[i][j];
        }
    }
    cout << f(0, 0, n) << endl;
    return 0;
}
// De tarea: Resolver este mismo con programación dinámica.
// Y buscar en OmegaUp -> Chocolates del agente nieve.
