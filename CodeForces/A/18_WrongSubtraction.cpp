#include <bits/stdc++.h>
// https://codeforces.com/contest/977/problem/A
// tag(s): Implementación
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    auto magico = [&](int &n, int &k) {
        do {
            if(k == 0) return n;
            if(n % 10 != 0) n--;
            else n /= 10;
        } while(k--);
    };

    cout << magico(n, k) << endl;
    return 0;
}
