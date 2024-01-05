#include <bits/stdc++.h>
using namespace std;

int main() {
    int poblacionMaxima;
    int numeroDias = 0;
    int numeroBacterias = 1; // Inicialmente hay una sola bactería

    cout << "Escribe la población máxima: ";
    cin >> poblacionMaxima;

    while(numeroBacterias <= poblacionMaxima) {
        numeroBacterias = numeroBacterias * 2;
        // Checamos si todavía no se llega al máximo
        if(numeroBacterias <= poblacionMaxima) {
            // Se incrementa el número de días en dos
            // Pues sólo al pasar dos días se duplica el número de bacterias
            numeroDias = numeroDias + 2;
        }
    }
    cout << "El número de bacterias es: " << numeroBacterias << endl;
    cout << "Y han pasado: " << numeroDias << " días." << endl;

    return 0;
}
