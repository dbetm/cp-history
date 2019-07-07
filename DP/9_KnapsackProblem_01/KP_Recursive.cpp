#include <bits/stdc++.h>
// Complejidad en tiempo: O(2^n)
// Complejidad en espacio: 2*n
using namespace std;
/* Retorna el máximo valor que puede ser llevado en una mochila de
capacidad W. */
int knapSack(int w, int wt[], int val[], int n) {
    // Caso base
    if(n == 0 || w == 0) return 0;
    /* Si el peso del n-esésimo item es más que la capacidad W, entonces
    este item no puede ser incluido en la solución óptima. */
    if(wt[n-1] > w) return knapSack(w, wt, val, n-1);
    /* Retornar el máximo de 2 casos:
    1) El n-enésimo item es incluido.
    2) El n-enésimo item no es incluido. */
    else
        return max(val[n-1] + knapSack(w-wt[n-1], wt, val, n-1),
            knapSack(w, wt, val, n-1));
}

int main() {
    int n, w;
    cout << "Número de items: ";
    cin >> n;
    int val[n];
    int wt[n];
    cout << "Escribe los pares valor-peso" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
    }
    cout << "Escribe el peso máximo de la mochila: ";
    cin >> w;
    cout << knapSack(w, wt, val, n) << endl;
    return 0;
}
