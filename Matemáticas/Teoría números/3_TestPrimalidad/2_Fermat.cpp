#include <bits/stdc++.h>

using namespace std;

// Resuelve a^n % p, O(log(n))
int binpow(int a, unsigned int n, int p);
// Test de primalidad de Fermat
bool esPrimo(unsigned int n, int k);

int main(int argc, char const *argv[]) {
    int n;
    int k = 20;
    cout << "Escribe el número: ";
    cin >> n;
    esPrimo(n, k) ? cout << n << " es primo\n" : cout << n << " es compuesto\n";
    return 0;
}

bool esPrimo(unsigned int n, int k) {
    // Casos de esquina
    if(n <= 1 || n == 4) return false;
    else if(n <= 3) return true; // 2 y 3

    // Intentar k veces
    while(k > 0) {
        // Seleccionar un número random entre [2- n-2]
        int a = 2 + rand() % (n - 4);
        // Pequeño teorema de Fermat
        if(binpow(a, n-1, n) != 1) return false;
        k--;
    }
    return true;
}

int binpow(int a, unsigned int n, int p) {
    int res = 1;
    a %= p;
    while (n > 0) {
        if(n & 1) res = (res * a) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return res;
}
