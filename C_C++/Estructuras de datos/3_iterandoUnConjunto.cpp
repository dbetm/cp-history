#include <iostream>
#include <set>

/*
Los iteradores son punteros que se utilizan para acceder a los elementos,
un iterador soporta el operador ++, lo cual significa que podemos usarlo
en sentencias de iteración(for).
*/

using namespace std;

int main() {
    set<int> conj;
    conj.insert(23);
    conj.insert(34);
    conj.insert(1);
    conj.insert(1024);
    conj.insert(57);

    for(set<int>::iterator it = conj.begin(); it != conj.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
