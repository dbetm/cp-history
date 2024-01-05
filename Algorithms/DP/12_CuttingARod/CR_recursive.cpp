#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> precios, int n) {
    if(n <= 0) return 0; // Caso base
    int max_val = INT_MIN; // Hipótesis

    for (int i = 0; i < n; i++) {
        max_val = max(max_val, precios[i] + cutRod(precios, n-i-1));
    }

    return max_val;
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
