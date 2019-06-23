#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

void _setup() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    _setup();
    int n, aux;
    cin >> n;
    vi normal(n);
    vi ordenado(n);
    vi impares;
    vi pares;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        normal[i] = aux;
        ordenado[i] = aux;
        if(i & 1) pares.push_back(aux);
        else impares.push_back(aux);
    }
    sort(ordenado.begin(), ordenado.end());
    sort(impares.begin(), impares.end());
    sort(pares.begin(), pares.end());

    // Mostramos los diferentes ordenamientos
    // 1) De menor a mayor
    for (int i = 0; i < n-1; i++) {
        cout << ordenado[i] << " ";
    }
    cout << ordenado[n-1] << endl;
    // 2) De manera inversa a la posición original
    for (int i = n-1; i > 0; i--) {
        cout << normal[i] << " ";
    }
    cout << normal[0] << endl;
    // 3) De mayor a menor
    for (int i = n-1; i > 0; i--) {
        cout << ordenado[i] << " ";
    }
    cout << ordenado[0] << endl;
    // 4) Impares de menor a mayor
    for (int i = 0; i < (int)impares.size()-1; i++) {
        cout << impares[i] << " ";
    }
    cout << impares[impares.size()-1] << endl;
    // 3)Pares de mayor a menor
    for (int i = pares.size()-1; i > 0; i--) {
        cout << pares[i] << " ";
    }
    cout << pares[0] << endl;
    return 0;
}
