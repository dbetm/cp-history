#include <bits/stdc++.h>
// https://www.codechef.com/problems/FLOW016
using namespace std;

long gcd(long a, long b) {
    return b ? gcd(b, a % b) : a;
}

long lcm(long a, long b, long gcdivisor) {
    return (a *  b) / gcdivisor;
}

int main() {
    int t;
    long a, b;
    // Número de casos
    cin >> t;
    for (long i = 0; i < t; i++) {
        cin >> a >> b;
        long gcdivisor = gcd(a, b);
        cout << gcdivisor << " " << lcm(a, b, gcdivisor) << endl;
    }
    return 0;
}
