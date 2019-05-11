#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Matanza-de-Binarios#problems
using namespace std;

int main() {
    int n, aux, cont = 0;
    cin >> n;

    while(n--) {
        cin >> aux;
        if(__builtin_popcount(aux) % 2 == 0) cont++;
    }

    cout << cont << endl;

    return 0;
}
