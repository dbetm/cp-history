#include <bits/stdc++.h>

using namespace std;

#define EPS 1.19209e-07

int main() {
    double num = 5.2234;
    // Imprimir con 6 decimales de precisión
    cout << fixed << setprecision(6) << num << endl;
    // Hacer comparación
    cout << EPS << endl;
    // Igual
    if(abs(num-5.2234) < EPS) cout << "hola" << endl;
    // Menor
    // a < b - eps
    // Mayor
    // a > b + eps

    // Truncado
    // floor(a + eps)
    return 0;
}
