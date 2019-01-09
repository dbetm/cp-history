#include <bits/stdc++.h>

using namespace std;

void obtenerRespuesta(int, int);

int main(int argc, char const *argv[]) {
    int numCasos, longitud, numBarras;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        cin >> longitud >> numBarras;
        obtenerRespuesta(longitud, numBarras);
    }
    return 0;
}

void obtenerRespuesta(int longitud, int numBarras) {
    vector <int> A(numBarras);
    for (int i = 0; i < numBarras; i++) {
        cin >> A[i];
    }
    bool seCompleta = false;
    for (int i = 0; i < (1 << numBarras); i++) {
        int size = 0;
        for (int j = 0; j < numBarras; j++) {
            if(i & (1 << j)) size += A[j];
        }
        if(size == longitud) {
            seCompleta = true;
            break;
        }
    }

    if(seCompleta) cout << "YES" << endl;
    else cout << "NO" << endl;
}
