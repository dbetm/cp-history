#include <bits/stdc++.h>

using namespace std;
typedef unsigned long int uli;

uli Hash[1000000];
int m = 1;

// Prototipos de funciones
uli sumaYSepara(int);
int contarIteraciones(int);

int main(int argc, char const *argv[]) {
    uli n;
    cin >> n;
    memset(Hash, 0, sizeof Hash);
    cout << contarIteraciones(sumaYSepara(n)) << endl;
    return 0;
}

// Implementación
uli sumaYSepara(int x) {
    uli suma = 0;
    uli aux;
    while(x > 0) {
        aux = x % 10;
        suma += pow(aux, 2);
        x /= 10;
    }
    Hash[suma]++;
    //cout << suma << endl;
    return suma;
}

int contarIteraciones(int x) {
    if(Hash[x] > 1) {
        return -1;
    }
    else if(x == 1) {
        return m;
    }
    m++;
    contarIteraciones(sumaYSepara(x));
}
