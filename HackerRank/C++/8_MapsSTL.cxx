#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
// https://www.hackerrank.com/challenges/cpp-maps/problem
using namespace std;
typedef long long int lli;
typedef vector<lli> vlli;

int main() {
    map<string, lli> mapa;
    lli q, type, y;
    string x;
    cin >> q; // Leer el número de consultas
    while(q--) {
        cin >> type;
        switch (type) {
            case 1: // Sumar la calificación "y" al estudiante "x".
                cin >> x >> y;
                try {
                    mapa[x] += y;
                }
                catch(...) {
                    lli aux = 0;
                    mapa.insert(make_pair(x, aux));
                }
                break;
            case 2: // volver 0 la calificación acumulada
                cin >> x;
                mapa[x] = 0;
                break;
            default: // mostrar
                cin >> x;
                lli marks = mapa[x];
                cout << marks << endl;
        }
    }
    return 0;
}
