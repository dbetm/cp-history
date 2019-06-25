#include <iostream>
#include <cmath>

using namespace std;

typedef int64_t i64;

i64 obtenerPotencias(i64);

int main() {
    for (size_t i = 1; i <= 40; i++) {
        cout << i << ": " << obtenerPotencias(i) << endl;
    }
    return 0;
}

i64 obtenerPotencias(i64 n) {
    i64 cont = 1, potencia, i = 2, repetidos = 0;
    //cin >> n;
    int a[n+1] = {0};

    do {
        i64 j = 2;
        if(pow(i, j) > n) break;
        //cont += sqrt(n) - 2;
        for (j = 2; j <= n; j++) {
            //if(j < i && i % j == 0) continue;
            potencia = pow(i, j);
            //cout << potencia << endl;
            if(potencia <= n) {
                //cout << i << "^" << j << "=" << potencia << " ";
                if(a[potencia] == 0) {
                    cont++;
                    a[potencia] = 1;
                }
                else {
                    repetidos++;
                }
            }
            else break;
        }
        i++;
    } while(true);
    //cout << " repetidos: " << repetidos << " ";
    return cont;
}
