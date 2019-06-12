#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Buscando-a-Tavo#problems
using namespace std;

int main() {
    string mensaje;
    int numAsteriscos = 0;
    getline(cin, mensaje);

    for (size_t i = 0; i < mensaje.length(); i++) {
        if(mensaje[i] == '*') numAsteriscos++;
    }

    if(numAsteriscos <= 1) cout << "BIEN" << endl;
    else if(numAsteriscos == 2) cout << "HAPPY" << endl;
    else cout << "BUSCAR A TAVO" << endl;

    return 0;
}
