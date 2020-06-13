#include <bits/stdc++.h>

#define MAX 10000

using namespace std;

int multiplicar(int, int[], int);

int main(int argc, char const *argv[]) {
    int resultado[MAX];
    int sizeRes;
    int n;

    resultado[0] = 1;
    sizeRes = 1;

    // Leer el número del cual se va a calcular su factorial,
    // tener presente que el resultado no debe tener más de 500 dígitos
    cin >> n;

    // Hacemos el cálculo del factorial
    for (int x = 2; x <= n ; x++) {
        sizeRes = multiplicar(sizeRes, resultado, x);
    }

    // Mostramos el resultado
    for (int i = sizeRes - 1; i >= 0; i--) {
        cout << resultado[i];
    }
    cout << "\n";
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


