#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/connecting-towns/problem
// Teorema de la multiplicación, conteo, artimética modular
using namespace std;

int main() {
    int t;
    int torres;
    int posiblesRutas;
    int totalRutas;
    // Número de casos
    cin >> t;
    for (int i = 0; i < t; i++) {
        // Número de torres
        cin >> torres;
        totalRutas = 1;
        for (int j = 0; j < torres-1; j++) {
            cin >> posiblesRutas;
            totalRutas = (totalRutas * posiblesRutas) % 1234567;
        }
        cout << totalRutas << "\n";
    }
    return 0;
}
