#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/arriba_del_promedio#problems
using namespace std;

int main() {
    int c, n, cont;
    double suma, prom;
    cin >> c;
    while(c--) {
        cin >> n;
        suma = 0;
        cont = 0;
        int cali[n];
        // leemos las calis y sumamos
        for (int i = 0; i < n; i++) {
            cin >> cali[i];
            suma += cali[i];
        }
        // promediamos y después contamos
        prom = suma / (double)n;
        for (int i = 0; i < n; i++) {
            if(cali[i] > prom) cont++;
        }
        // Mostramos el porcentaje
        printf("%0.3f%%\n", ((double)cont*100)/(double)n);
    }
    return 0;
}
