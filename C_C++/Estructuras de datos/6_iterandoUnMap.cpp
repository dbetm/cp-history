#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, int> ap1;
    ap1.insert(make_pair('a', 23));
    ap1.insert(make_pair('b', 34));
    // Mostramos los elementos
    cout << ap1['a'] << endl;
    cout << ap1['b'] << endl;

    // Dado que no existe la clave 'c', se creará y de valor será un 0
    cout << ap1['c'] << endl;

    // Acceso a las llaves y valores mediante iteradores
    for (map<char, int>::iterator it = ap1.begin(); it != ap1.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
