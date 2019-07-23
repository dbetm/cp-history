#include <bits/stdc++.h>

using namespace std;

int64_t binpow(int64_t base, int64_t exponente, int64_t mod) {
    base %= mod;
    int64_t res = 1;
    while(exponente > 0) {
        if(exponente & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exponente >>= 1;
    }
    return res;
}

int main() {
    int64_t n, mod = 1e9+7;
    cin >> n;

    int64_t res = 10 * binpow(9, n-1, mod);

    cout << res << endl;

    return 0;
}
