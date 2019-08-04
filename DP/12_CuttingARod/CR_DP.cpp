#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> precios, int n) {
    int tabla[n+1];
    tabla[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, precios[j] + tabla[i-j-1]);
        }
        tabla[i] = max_val;
    }

    return tabla[n];
}

int main() {
    int n;
    cout << "Escribe la longitud de la varilla: ";
    cin >> n;
    cout << "Escribe los n precios para cada segmento: " << endl;
    vector <int> precios(n);
    for (int i = 0; i < n; i++) cin >> precios[i];
    cout << "Valor máximo que se puede obtener: " << cutRod(precios, n) << endl;
    return 0;
}
