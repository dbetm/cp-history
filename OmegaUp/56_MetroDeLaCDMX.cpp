#include <bits/stdc++.h>
// Respuesta parcialmente correcta
using namespace std;
int p, d, q;
map<int, vector<int>> puertas;

void mostrarPuertas();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> p >> d >> q;
    int index, numPuertas, indexito;
    for (int i = 0; i < d; i++) {
        cin >> index;
        cin >> numPuertas;
        for (int j = 0; j < numPuertas; j++) {
            cin >> indexito;
            puertas[index].push_back(indexito);
        }
    }
    //mostrarPuertas();
    int puertasIniciales, indexPuertaAbierta;
    for (int i = 0; i < q; i++) {
        cin >> puertasIniciales;
        int tabla[p] = {};
        for (int j = 0; j < puertasIniciales; j++) {
            cin >> indexPuertaAbierta;
            tabla[indexPuertaAbierta-1] = 0;
            vector <int> inds = puertas[indexPuertaAbierta];
            for (unsigned int k = 0; k < inds.size(); k++) {
                tabla[inds[k]-1] = 1;
            }
        }
        bool flag = true;
        for (int j = 0; j < p; j++) {
            if(tabla[j] == 1) {
                flag = false;
                break;
            }
        }
        if(flag) cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}

void mostrarPuertas() {
    map<int, vector<int>>::iterator itr;
    for (itr = puertas.begin(); itr != puertas.end(); ++itr) {
        cout << itr->first << ": ";
        for (unsigned int j = 0; j < itr->second.size(); j++) {
            cout << itr->second[j] << " ";
        }
        cout << endl;
    }
}
