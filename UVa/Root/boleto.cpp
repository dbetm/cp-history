#include <bits/stdc++.h>

using namespace std;

int sumarDigitos(int numero) {
    int suma = 0;
    while (numero / 10 > 0) {
        suma += numero % 10;
        numero /= 10;
    }
    return suma + (numero % 10);
}

int main(int argc, char* argv[]) {
    long int numero;
    cout << "Escribe el número: ";
    cin >> numero;
    int sumDig = sumarDigitos(numero);
    if(sumDig == 21) cout << "Has ganado!" << endl;
    else if(sumDig < 21)
        cout << "Faltan: " << 21 - sumDig << endl;
    else
        cout << "Se pasa con: " << sumDig - 21 << endl;
    return 0;
}
