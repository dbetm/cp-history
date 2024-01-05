#include <bits/stdc++.h>

using namespace std;

void funcionesModificadoras(map<char, int>);

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

    // Mostrar el uso de funciones modificadores
    funcionesModificadoras(ap1);

    return 0;
}

void funcionesModificadoras(map<char, int> ap) {
    if(ap.count('a') == 1) cout << "a está en el mapa" << endl;
    else cout << "a no está en el mapa" << endl;

    if(ap.find('d') != ap.end()) cout << "d está en el mapa" << endl;
    else cout << "d no está en el mapa" << endl;

    if(ap.lower_bound('b') != ap.upper_bound('b'))
        cout << "b está en el mapa" << endl;
    else
        cout << "b no está en el mapa" << endl;

    // .erase(inicio, fin);

    /*Está función elimina elementos desde una posición inicial (inicio) hasta
    otra posición (fin), inicio y fin deben ser iteradores. La complejidad
    es lineal*/

    // .erase(llave);

    /*Está función busca el elemnto y lo elimina, llave debe ser un tipo de
    dato aceptado por la aplicación. La complejidad de está función es
    O(log 2 N).*/
}
