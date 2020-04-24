#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/OMI2015LENGUAJE1/#problems
// Tag(s): DP, implementación
using namespace std;
typedef long long int lli;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, k;
    lli maximo, suma = 0;
    cin >> n >> k;

    lli actual, anterior;
    lli dif[n];
    cin >> anterior;
    for (size_t i = 0; i < n-1; i++) {
        cin >> actual;
        dif[i] = actual - anterior;
        anterior = actual;
    }
    // calcular hasta los primeros k-1 elementos
    for (size_t i = 0; i < k-1; i++) {
        suma += dif[i];
    }
    // apuntadores
    int a, b;
    maximo = suma;

    // calcular los siguientes elementos
    for (a = 0, b = k-1; b < n-1; a++, b++) {
        suma -= dif[a];
        suma += dif[b];
        maximo = max(maximo, suma);
    }

    cout << maximo << endl;

    return 0;
}
