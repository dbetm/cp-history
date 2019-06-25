#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/CR-Buscando-repeticiones#problems
using namespace std;

int main(){
    string palabra, respaldo, aux = "";
    char c;
    int cont = 0;
    cin >> palabra;
    respaldo = palabra;
    transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

    while(cin.get(c)) {
        c = tolower(c);
        //cout << c << endl;
        if(c >= 'a' && c <= 'z') {
            aux += c;
        }
        else {
            if(aux == palabra) cont++;
            aux = "";
        }
    }
    if(cont == 1) {
        cout << respaldo << " se repite 1 vez." << endl;
    }
    else {
        cout << respaldo << " se repite " << cont << " veces." << endl;
    }

    return 0;
}
