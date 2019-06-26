#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/CR-Apenas-Pase#problems
using namespace std;

int main() {
    double promAmigos, promedio, suma = 0;
    cin >> promAmigos;
    int calis;
    cin >> calis;
    for (int i = 0; i < calis; i++) {
        cin >> promedio;
        suma += promedio;
    }
    double res = suma / (double)calis;
    if(res > promAmigos) cout << "Presume" << endl;
    else cout << "Ladra" << endl;
    return 0;
}
