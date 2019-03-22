#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/DP-Generica#problems
using namespace std;

int main() {
    uint64_t n;
    cin >> n;

    uint64_t a[] = {1, 0};

    while(n > 0) {
        if(n & 1) a[0] += a[1];
        else a[1] += a[0]; // par
        n /= 2;
    }

    cout << a[0] << endl;

    return 0;
}
