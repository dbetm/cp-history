#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int64_t n;
    long double numTareas, puntaje;
    long double promedio, suma = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> numTareas >> puntaje;
        if(numTareas == 0 || puntaje == 0) puntaje = 10;
        suma += puntaje;
    }

    promedio = suma / n;
    cout << promedio << endl;
    return 0;
}
