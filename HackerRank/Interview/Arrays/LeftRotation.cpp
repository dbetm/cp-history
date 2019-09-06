#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/array-left-rotation/problem
// Se trata de rotar, a la izquierda,
// q posiciones a cada elemento de un arreglo.
using namespace std;

int main() {
    int n, q;
    // Se lee el número de enteros y la cantidad de posiciones a desplazar
    cin >> n >> q;
    int A[n];
    // Leemos cada entero, ya agregando el elemento en su posición después de
    // la rotación.
    for (int i = n - 1; i >= 0; i--) cin >> A[(i + q) % n];
    // Mostramos el resultado
    for (int i = n - 1; i >= 0; i--) cout << A[i] << " ";
    cout << endl;

    return 0;
}
