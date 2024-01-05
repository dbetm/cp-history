#include <bits/stdc++.h>
// Time Complexity: O(nk^2)
// Auxiliary Space: O(nk)
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
    // Una matriz bidimensional donde cada eggFloor[i][j] representará el
    // mínimo de intentos necesarios para i huevos y j pisos.
    int eggFloor[n+1][k+1];
    int res;

    // ### CASOS BASE ###

    // Se necesita al menos 1 intento para 1 piso, y 0 intentos para 0 pisos
    for (int i = 1; i <= n; i++) {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    // Siempre necesitamos j intentos para un huevo y j pisos
    for (int j = 1; j <= k; j++) {
        eggFloor[1][j] = j;
    }

    // ### Construimos el resto de la solución óptima ###

    // Se itera donde se va considerando cada vez un huevo más
    for (int i = 2; i <= n; i++) {
        // Para considerar el comenzar desde todos los pisos
        for (int j = 2; j <= k; j++) {
            // Hipótesis, se ocupan "infinitos" jaja intentos.
            eggFloor[i][j] = INT_MAX;
            // Se va iterando hasta el j-ésimo piso.
            for (int x = 1; x <= j; x++) {
                // max(cuando se rompe el huevo, cuando no se rompe) :D
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                if(res < eggFloor[i][j]) eggFloor[i][j] = res;
            }
        }
    }

    return eggFloor[n][k];
}
