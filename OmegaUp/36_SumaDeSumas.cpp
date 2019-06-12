#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Suma-de-sumas#problems
using namespace std;

int main() {
    int64_t n, k = 0;
    cin >> n;
    for (int64_t i = 1; i <= n; i++) {
        k += i*i;
    }
    cout << k << endl;
    return 0;
}
