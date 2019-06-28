#include <bits/stdc++.h>
// Parcialmente correcta
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int emociones[n];
    int64_t diferencias[n];
    int64_t pivote, suma = LLONG_MIN, aux = 0;
    //bool bandera = false;

    if(k == 1) {
        for (int i = 0; i < n; i++) {
            cin >> aux;
            suma = max(aux, suma);
        }
    }
    else if(k == 2) {
        int64_t actual, anterior;
        cin >> anterior;
        for (int i = 1; i < n; i++) {
            cin >> actual;
            aux = actual-anterior;
            if(suma < aux) suma = aux;
            anterior = actual;
        }
    }
    else {
        cin >> emociones[0] >> emociones[1];
        diferencias[0] = emociones[1] - emociones[0];
        aux = diferencias[0];
        pivote = 0;

        int i;
        for (i = 2; i < n; i++) {
            cin >> emociones[i];
            diferencias[i-1] = emociones[i] - emociones[i-1];
            aux += diferencias[i-1];
            //cout << diferencias[i-1] << endl;
            if(i % (k-1) == 0) {
                if(suma < aux) suma = aux;
                break;
            }
        }
        //cout << aux << endl;
        aux -= diferencias[pivote++];

        for (int j = i+1; j < n; j++) {
            cin >> emociones[j];
            diferencias[j-1] = emociones[j] - emociones[j-1];
            aux += diferencias[j-1];
            //cout << aux << endl;
            if(suma < aux) suma = aux;
            aux -= diferencias[pivote++];
        }
    }
    cout << (int64_t)suma << endl;
    return 0;
}
