#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli extendedGCD(lli a, lli b, lli &x, lli &k);
bool findAnySolution(lli a, lli b, lli c, lli &x0, lli &k0, lli &g);

int main() {
    // ax + nk = b
    lli a, n, b;
    lli x, y, g;

    cout << "Type a, n y b:" << endl;
    cin >> a >> n >> b;

    if(findAnySolution(a, n, b, x, y, g)) {
        cout << "The given Diophantine equation solution(s): " << endl;
        cout << "x is: " << x << endl;
        cout << "ax ≡ b (mod n)" << endl;
        cout << a << "*" << x << " ≡ " << b << "(mod " << n << ")" << endl;
        cout << ((a*x) % n) << " = " << (b % n) << endl;
    }
    else cout << "It doesn't have any solution" << endl;

    return 0;
}

bool findAnySolution(lli a, lli n, lli b, lli &x0, lli &k0, lli &g) {
    g = extendedGCD(a, n, x0, k0);
    if(b % g) return false;

    x0 *= b/g;
    k0 *= b/g;
    if(a < 0) x0 = -x0;
    if(n < 0) k0 = -k0;
    return true;
}

lli extendedGCD(lli a, lli n, lli &x, lli &k) {
    if(a == 0) {
        x = 0;
        k = 1;
        return n;
    }

    lli x1, k1;
    lli d = extendedGCD(n % a, a, x1, k1);
    x = k1 - (n/a) * x1;
    k = x1;
    return d;
}
