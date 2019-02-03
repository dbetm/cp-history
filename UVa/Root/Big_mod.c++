#include <bits/stdc++.h>

using namespace std;

// b^p mod M
int getBigMod(int b, int p, int m) {
    b %= m;
    int resultado = 1;
    while(p > 0) {
        if(p & 1) resultado = resultado * b % m;
        b = b * b % m;
        p >>= 1;
    }
    return resultado;
}

int main() {
    int b, m, p;
    while(cin >> b >> p >> m) {
        cout << getBigMod(b, p, m) << endl;
    }
    return 0;
}
