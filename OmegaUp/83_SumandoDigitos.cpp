#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Sumando-Digitos#problems
using namespace std;

int64_t sumarDigitos(int a, int b);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, a, b;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << "Case #" << i << " = " << sumarDigitos(a, b) << endl;
    }

    return 0;
}

int64_t sumarDigitos(int a, int b) {
    int64_t suma = 0;
    for (int i = a; i <= b; i++) {
        int n = i;
        for (; n > 0; suma += n % 10, n /= 10);
    }
    return suma;
}
