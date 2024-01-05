#include <bits/stdc++.h>

using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a % b) : a;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int64_t numerador, denominador;
    int64_t n = 0, m = 1;

    while(cin >> numerador >> denominador) {
        n = n*denominador + m*numerador;
        m = m * denominador;
    }

    int64_t factor = gcd(n, m);

    n /= factor;
    m /= factor;

    if((n < 0 && m < 0) || m < 0) {
        n *= -1;
        m *= -1;
    }

    cout << n << " / " << m << endl;

    return 0;
}
