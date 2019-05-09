#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Division-de-factorial#problems
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int64_t res = 1;
    int lim = a - b;

    for (int i = 0; i < lim; i++, a--) res *= a;

    cout << res << endl;

    return 0;
}
