#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/B-I-N-A-R-Y#problems
using namespace std;

int main() {
    int n;
    cin >> n;
    int tam = log2(n) + 1;
    int max = 0;
    int menor = 0;
    int numUnos = __builtin_popcount(n);
    int aux = numUnos;
    // max
    for (int i = 0; i < tam; i++) {
        if(aux > 0) {
            max |= (1 << ((tam-1) - i));
            aux--;
        }
        else break;
    }
    // menor
    aux = numUnos - 1;
    menor |= 1 << (tam-1);
    for (int i = 0; i < tam-1; i++) {
        if(aux > 0) {
            menor |= (1 << i);
            aux--;
        }
        else break;
    }
    cout << max << " " << menor << endl;
    return 0;
}
