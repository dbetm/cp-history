#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Busqueda-de-Entropia#problems
using namespace std;

int main() {
    string cadena;
    getline(cin, cadena);
    int64_t puntos = 0;
    for (unsigned int i = 0; i < cadena.size(); i++) {
        if(cadena[i] > 'F' && cadena[i] < 'K') puntos += 15;
        else puntos += 11;
    }

    cout << puntos << endl;
    return 0;
}
