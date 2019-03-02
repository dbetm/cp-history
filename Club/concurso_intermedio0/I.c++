#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Numeros-Felices#problems
using namespace std;

int H[1000000];

int pasos = 1;

int separaElevaSuma(int n);
int contarPasos(int n);

int main() {
    int n;
    cin >> n;
    cout << contarPasos(separaElevaSuma(n)) << endl;
    return 0;
}

int separaElevaSuma(int n) {
    int suma = 0;
    int dig;
    while (n > 0) {
        // separa
        dig = n % 10;
        // elevar y sumar
        suma += pow(dig, 2);
        n /= 10;
    }
    H[suma]++;
    return suma;
}

int contarPasos(int n) {
    if(H[n] > 1) return -1;
    else if(n == 1) return pasos;
    pasos++;
    contarPasos(separaElevaSuma(n));
}
