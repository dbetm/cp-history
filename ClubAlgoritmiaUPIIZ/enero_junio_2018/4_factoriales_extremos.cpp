#include <bits/stdc++.h>

// (a*b) % c = (a % c) * (b % c) % c
using namespace std;

int calcularFactorialExtremo(int, int);

int main() {
    int n, m;
    cin >> n >> m;

    cout << calcularFactorialExtremo(n, m) << endl;

    return 0;
}

int calcularFactorialExtremo(int n, int m) {
    unsigned long int res = 1;
    if(n >= m) return 0;
    for (int i = 2; i <= n; i++) {
        res *= i % m;
    }
    return res % m;
}
