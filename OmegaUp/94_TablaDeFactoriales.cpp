#include <bits/stdc++.h>

#define MAX 10000

using namespace std;

int multiplicar(int, int[], int);

int main(int argc, char const *argv[]) {
    cout << "0! = 1\\n";
    for (size_t t = 1; t <= 100; t++) {
        int resultado[MAX];
        int sizeRes;
        int n = t;

        resultado[0] = 1;
        sizeRes = 1;

        // Hacemos el cálculo del factorial
        for (int x = 2; x <= n ; x++) {
            sizeRes = multiplicar(sizeRes, resultado, x);
        }
        cout << t << "! = ";
        // Mostramos el resultado
        for (int i = sizeRes - 1; i >= 0; i--) {
            cout << resultado[i];
        }
        cout << "\\n";
    }
    return 0;
}

int multiplicar(int sizeRes, int resultado[], int x) {
    // Inicializamos el acarreo
    int carry = 0;
    int subproducto;

    for (int i = 0; i < sizeRes; i++) {
        subproducto = resultado[i] * x + carry;
        carry = subproducto / 10;
        resultado[i] = subproducto % 10;
    }

    while (carry) {
        resultado[sizeRes] = carry % 10;
        carry /= 10;
        sizeRes++;
    }

    return sizeRes;
}
