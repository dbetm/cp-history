#include <iostream>
#include <cmath>
#include <map>

using namespace std;

typedef int64_t i64;

int main() {
    i64 n, cont = 1, potencia, i = 2;
    cin >> n;
    unsigned int tamAntes, tamDespues;
    map<i64, i64> potencias;
    do {
        i64 j = 2;
        if(pow(i, j) > n) break;
        //cont += sqrt(n) - 2;
        for (j = 2; j <= n; j++) {
            potencia = pow(i, j);
            //cout << potencia << endl;
            if(potencia <= n) {
                tamAntes = potencias.size();
                potencias.insert(pair<i64, i64>(potencia, 0));
                tamDespues = potencias.size();
                if(tamDespues > tamAntes) {
                    cont++;
                    if(tamDespues > 1000)
                        potencias.erase(potencias.begin());
                }
            }
            else break;
        }
        i++;
    } while(true);

    cout << cont << endl;
    return 0;
}
