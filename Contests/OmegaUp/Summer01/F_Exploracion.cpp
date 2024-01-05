#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
typedef long int li;
vector<li> puntosPositivos;
vector<li> puntosNegativos;
int indexPositivos = 0;
int indexNegativos = 0;
int tamPlus, tamNeg;
// Enfoque Greedy no sirve
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    li punto, n, minutos, minutosConsumidos = 0, numMarcas = 0, x = 0;
    li t1, tt1, t2, tt2, tiempo;
    cin >> minutos >> n;

    while(n--) {
        cin >> punto;
        if(punto < 0) puntosNegativos.push_back(punto);
        else puntosPositivos.push_back(punto);
    }
    tamPlus = puntosPositivos.size();
    tamNeg = puntosNegativos.size();

    sort(puntosNegativos.rbegin(), puntosNegativos.rend());
    sort(puntosPositivos.begin(), puntosPositivos.end());

    while(true) {
        //watch(x);
        t1 = t2 = INT_MAX;
        if(indexPositivos < tamPlus) {
            t1 = abs(puntosPositivos[indexPositivos]);
            tt1 = abs(x-puntosPositivos[indexPositivos]);
        }
        if(indexNegativos < tamNeg) {
            t2 = abs(puntosNegativos[indexNegativos]);
            tt2 = abs(x-puntosNegativos[indexNegativos]);
        }
        if(t1 <= t2) {
            tiempo = tt1;
            x = puntosPositivos[indexPositivos];
            indexPositivos++;
        }
        else {
            tiempo = tt2;
            x = puntosNegativos[indexNegativos];
            indexNegativos++;
        }
        //watch(tiempo);
        if(minutosConsumidos + tiempo <= minutos) {
            numMarcas++;
            minutosConsumidos += tiempo;
        }
        else break;
    }

    cout << numMarcas << endl;
    return 0;
}
