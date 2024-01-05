#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string cadena;
    int cont = 0, suma = 0;
    cin >> cadena;
    transform(cadena.begin(), cadena.end(), cadena.begin(), ::toupper);
    for (unsigned int i = 0; i < cadena.size(); i++) suma += (int)cadena[i];
    //cout << suma << endl;
    for (int i = 1; i <= suma; i++) {
        if(suma % i == 0) cont++;
    }

    cout << cont << endl;

    return 0;
}
