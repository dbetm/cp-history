#include <bits/stdc++.h>

using namespace std;

void rabinKarp(string &texto, string &patron, vector<int> &ocurrencias);

int main() {
    string texto;
    string patron;
    cout << "Escribe el texto: " << endl;
    getline(cin, texto);
    cout << "Escribe el patrón a buscar" << endl;
    cin >> patron;

    vector<int> ocurrencias;
    rabinKarp(texto, patron, ocurrencias);
    cout << "Hay ocurrencias en las posiciones: " << endl;
    int n = ocurrencias.size();
    for (int i = 0; i < n; i++) {
        cout << "i: " << ocurrencias[i] << endl;
    }

    return 0;
}

void rabinKarp(string &texto, string &patron, vector<int> &ocurrencias) {
    int t = texto.size(), s = patron.size();
    long long p = 31, m = 1e9 + 9;
    // Calcular las potencias que se necesitan
    int n = max(t, s);
    long long potencias[n];
    potencias[0] = 1;
    for (int i = 1; i < n; i++) {
        potencias[i] = (potencias[i-1] * p) % m;
    }

    // Calcular el hash del patrón s
    long long hashPatron = 0;
    for (int i = 0; i < s; i++) {
        hashPatron = (hashPatron + (patron[i] - 'a' + 1) * potencias[i]) % m;
    }

    // Calcular los hashes para cada prefijo del texto
    vector<long long> hashesTxt(t+1, 0);
    for (int i = 0; i < t; i++) {
        hashesTxt[i+1] = (hashesTxt[i] + (texto[i] - 'a' + 1) * potencias[i]) % m;
    }

    // Comparar
    long long hashActual;
    for (int i = 0; i < t - s + 1; i++) {
        hashActual = (hashesTxt[i + s] + m - hashesTxt[i]) % m;
        if(hashActual == (hashPatron * potencias[i] % m)) {
            ocurrencias.push_back(i);
        }
    }
}
