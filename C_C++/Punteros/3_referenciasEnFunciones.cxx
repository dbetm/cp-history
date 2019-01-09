#include <bits/stdc++.h>
// Programa que muestra el uso de referencias en las funciones
using namespace std;
//Prototipos de funciones

// 1a función que intercambia dos valores
void exchange(int *refA, int *refB);

// 2a función -sobrecargada- que intercambia dos valores
void exchange(int &refA, int &refB);

int main(int argc, char const *argv[]) {
    // Definimos un dato y su referecia
    int a, b;

    cout << "Asignamos valores" << endl;
    a = 45;
    b = 21;
    cout << "Valores: a = " << a << ", b = " << b << endl;
    cout << "Hacemos intercambio con exchange(int *refA, int *refB): " << endl;
    // Con esta llamada invocamos la primer función
    exchange(&a, &b);
    cout << "Valores: a = " << a << ", b = " << b << endl;

    cout << "Hacemos intercambio con exchange(int &refA, int &refB): " << endl;
    // Con esta llamada invocamos la segunda función
    exchange(a, b);
    cout << "Valores: a = " << a << ", b = " << b << endl;
    cout << "The end" << endl;
    return 0;
}

// Implementación de la primer función
void exchange(int *refA, int *refB) {
    int temp = *refA;
    *refA = *refB;
    *refB = temp;
}

// Implementación de la segunda función
void exchange(int &refA, int &refB) {
    int temp = refA;
    refA = refB;
    refB = temp;
}
