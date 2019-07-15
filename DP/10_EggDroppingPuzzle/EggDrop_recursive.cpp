#include <bits/stdc++.h>

using namespace std;

int eggDrop(int n, int k);

int main() {
    int n, k;
    cout << "Ingresa el número de huevos: ";
    cin >> n;
    cout << "Ingresa el número de pisos: ";
    cin >> k;
    cout << "El mínimo número de intentos en el peor caso es: ";
    cout << eggDrop(n ,k) << endl;
    return 0;
}

int eggDrop(int n, int k) {
    // Si k = 1, se requiere al menos 1 intento
    // Si k = 0, no se puede hacer ningún intento
    if(k <= 1) return k;
    // Si solo es un huevo, se ocupan k intentos, uno por cada piso
    if(n == 1) return k;
    int minNumIntentos = INT_MAX;
    // Se itera desde el piso 1 hasta el piso k
    for (int i = 1; i <= k; i++) {
        minNumIntentos = min(minNumIntentos, max(eggDrop(n-1, i-1), eggDrop(n, k-i)));
    }
    // Es el mínimo número de intentos encontrados recursivamente más el actual (+1)
    return minNumIntentos + 1;
}
