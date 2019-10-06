#include <bits/stdc++.h>

using namespace std;
#define INF 9999

void generateWordWrap(vector<int> l, int n, int m);

int main() {
    string text;
    int cont = 0, m;
    cout << "Ingresa el texto: ";
    getline(cin, text);
    vector<int> l;
    for (size_t i = 0; i < text.size(); i++) {
        if((int)text[i] != 32) cont++;
        else {
            l.push_back(cont);
            cont = 0;
        }
    }
    l.push_back(cont);
    cout << "Ingresa el tamaño máximo de línea: ";
    cin >> m;
    cout << "l[]" << endl;
    for (int i = 0; i < l.size()-1; i++) {
        cout << l[i] << " ";
    }
    cout << l[l.size()-1] << endl;
    generateWordWrap(l, l.size(), m);
    return 0;
}

void generateWordWrap(vector<int> l, int n, int m) {
    int extras[n+1][n+1];
    int costosTotalOptimo[n+1];
    int solucion[n+1];
    int costosPorLinea[n+1][n+1];
    // Espacios extra para palabras de i a j, por línea
    for (int i = 1; i <= n; i++) {
        extras[i][i] = m - l[i-1];
        for (int j = i+1; j <= n; j++) {
            extras[i][j] = extras[i][j-1] - l[i-1];
        }
    }
    cout << "Extras" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) cout << extras[i][j] << " ";
        cout << endl;
    }

    // Costo por línea, la cual tiene palabras de i a j
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if(extras[i][j] < 0) costosPorLinea[i][j] = INF;
            else if(i == n) costosPorLinea[i][j] = 0;
            else costosPorLinea[i][j] = extras[i][j] * extras[i][j];
        }
    }

    cout << "Costos por línea" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) cout << costosPorLinea[i][j] << " ";
        cout << endl;
    }

    // Costo óptimo hasta considerar j palabras
    costosTotalOptimo[0] = 0; // caso base
    for (int j = 1; j <= n; j++) {
        costosTotalOptimo[j] = INF;
        for (int i = 1; i <= j; i++) {
            if(costosTotalOptimo[i-1] != INF && costosPorLinea[j][i] != INF) {
                if(costosTotalOptimo[j] < costosPorLinea[j][i] + costosTotalOptimo[j-1]) {
                    costosTotalOptimo[j] = costosPorLinea[j][i] + costosTotalOptimo[j-1];
                    solucion[j] = i;
                }
            }
        }
    }

    cout << "Costos totales óptimos:" << endl;
    for (int i = 0; i < n; i++) {
        cout << costosTotalOptimo[i] << " ";
    }
    cout << costosTotalOptimo[n] << endl;
}
