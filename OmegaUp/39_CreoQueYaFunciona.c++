#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Creo-que-ya-funciona#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    string cadena = "";
    bool bandera = false;

    while(cin >> c) {
        if(c != '0' && c != '1') {
            bandera = true;
            break;
        }
        cadena += c;
    }

    if(bandera) {
        cadena = "10101";
        while(cin >> c) {
        }
    }

    cout << cadena << endl;
    return 0;
}
