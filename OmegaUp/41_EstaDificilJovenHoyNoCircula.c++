#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Esta-dificil-joven-hoy-no-circul#problems
using namespace std;

typedef long int li;
typedef long long int lli;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    li n, d, pares = 0, impares = 0;
    lli m, suma = 0;
    cin >> n;
    int aux;

    while(n--) {
        cin >> aux;
        if(aux & 1) impares++;
        else pares++;
    }

    cin >> d >> m;

    if(d & 1) { // día impar
        suma = pares * m;
    }
    else {
        suma = impares * m;
    }

    cout << suma << endl;

    return 0;
}
