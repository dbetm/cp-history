#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/potencias-y-modulos#problems
using namespace std;

int64_t binpow(int64_t a, int64_t b, int64_t m) {
    a %= m;
    int64_t res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    int64_t x, y, z;
    cin >> x >> y >> z;
    int64_t res = binpow(x, y, z);
    cout << res << endl;
    return 0;
}
