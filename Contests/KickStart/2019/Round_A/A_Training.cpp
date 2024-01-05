#include <bits/stdc++.h>

using namespace std;

int64_t obtenerMinimoHoras(vector <int> habilidades, int p);
void display(vector <int> v);

int main(int argc, char const *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;      // Número de casos
    int n, p;   // Cantidad de jugadores y tamaño del equipo;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> p;
        vector<int> habilidades(n);
        for (int j = 0; j < n; j++) cin >> habilidades[j];
        sort(habilidades.begin(), habilidades.end());
        cout << "Case #" << (i+1) << ": " << obtenerMinimoHoras(habilidades, p) << "\n";
    }
    return 0;
}

int64_t obtenerMinimoHoras(vector <int> habilidades, int p) {
    int64_t minHoras = 150000;
    // display(habilidades);
    for (unsigned int i = 0; i <= habilidades.size() - p; i++) {
        int64_t diferencia = 0;
        int64_t mayor = habilidades[i+p-1];
        int lim = i;
        for (int j = i+p-2; j >= lim; j--) {
            diferencia += mayor - habilidades[j];
        }
        minHoras = min(diferencia, minHoras);
    }

    return minHoras;
}

void display(vector <int> v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
