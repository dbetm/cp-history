#include <bits/stdc++.h>

using namespace std;
#define INF 9999

void generateWordWrap(vector<int> l, int n, int m);
int printSolution(int solucion[], int n);
/* Ejemplo de entrada:
Texto: "aaa bb cc ddddd"
-- Longitudes: 3 2 2 5
Longitud de línea: 6
*/

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
    for (int i = 0; i < (int)l.size()-1; i++) {
        cout << l[i] << " ";
    }
    cout << l[l.size()-1] << endl;
    generateWordWrap(l, l.size(), m);
    return 0;
}

void generateWordWrap(vector<int> l, int n, int m) {
    int extras[n+1][n+1];
    int costosPorLinea[n+1][n+1];
    int costoOptimo[n+1];
    int solucion[n+1];
    // Número de espacios extra que quedan de tomar de la palabra i a la j
    // Notar que i así como j comienzan a contarse a partir del 1
    for (int i = 1; i <= n; i++) {
        extras[i][i] = m - l[i-1];
        for (int j = i+1; j <= n; j++) {
            // se le resta 1 para contar el espacio entre palabras
            extras[i][j] = extras[i][j-1] - l[j-1] - 1;
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
            // tomando las palabras de i a j ya no cabe en la línea
            if(extras[i][j] < 0) costosPorLinea[i][j] = INF;
            // porque ya es la última línea
            else if(i == n) costosPorLinea[i][j] = 0;
            // Cabe en la línea, así que calculamos el costo de línea, ex*ex
            else costosPorLinea[i][j] = extras[i][j] * extras[i][j];
        }
    }

    cout << "Costos por línea" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) cout << costosPorLinea[i][j] << " ";
        cout << endl;
    }

    // Costo óptimo hasta considerar j palabras
    costoOptimo[0] = 0; // caso base
    for (int j = 1; j <= n; j++) {
        costoOptimo[j] = INF;
        for (int i = 1; i <= j; i++) {
            if(costoOptimo[i-1] != INF && costosPorLinea[i][j] != INF) {
                if(costoOptimo[j] > costosPorLinea[i][j] + costoOptimo[i-1]) {
                    costoOptimo[j] = costosPorLinea[i][j] + costoOptimo[i-1];
                    solucion[j] = i;
                }
            }
        }
    }

    cout << "Costos totales óptimos:" << endl;
    for (int i = 0; i < n; i++) {
        cout << costoOptimo[i] << " ";
    }
    cout << costoOptimo[n] << endl;

    printSolution(solucion, n);
}

// Con está función respondemos a la pregunta
// De qué palabra a qué palabra se toman en la x línea
//...
// así hasta que ya se hayan considerado las n palabras.
int printSolution(int solucion[], int n) {
    int k;
    if(solucion[n] == 1) k = 1;
    else k = printSolution(solucion, solucion[n]-1) + 1;
    cout << "Line number " << k << " from word no. " << solucion[n] << " to " << n << endl;
    return k;
}
