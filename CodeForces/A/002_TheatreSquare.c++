#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int64_t n, m, a, aux, tmp;
    cin >> n >> m >> a;
    if(n < m) {
        aux = n;
        n = m;
        m = aux;
    }

    // Ancho
    int64_t total = m/a;
    if(m % a > 0) total++;

    n = n-a;

    // Alto
    tmp = n/a;
    if(n % a > 0) tmp++;

    tmp *= total;
    total += tmp;
    cout << total << endl;
    return 0;
}
