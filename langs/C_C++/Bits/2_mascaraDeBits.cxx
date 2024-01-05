#include <bits/stdc++.h>

/*
Máscara de bits o BitMask es un algoritmo sencillo que se utiliza para
calcular todos los subconjuntos de un conjunto.
*/
using namespace std;

void displayArray(int A[], int n) {
    for (int i = n; i >= 0; i--) {
        cout << A[i];
    }
    cout << "\n";
}

int main(int argc, char const *argv[]) {
    int n;
    // El siguiente algoritmo imprime del 0 al n - 1 números base 2.
    cout << "N: ";
    cin >> n;
    int A[(int)log(n)];
    for (int i = 0; i < n; i++) {
        cout << i << " >> ";
        for (int j = 0; j < log(n); j++) {
            if(i & (1 << j)) A[j] = 1;
            else A[j] = 0;
        }
        displayArray(A, log(n));
    }
    return 0;
}
