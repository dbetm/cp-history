# include <iostream>
# include <set>
// Programa que muestra el uso de algunas funciones aplicables a la estructura
// de datos no lineal, conjunto.
using namespace std;

int main () {
    // Se declara el conjunto
    set<int> conj;
    // Se insertan los elementos
    conj.insert(12);
    conj.insert(2);
    conj.insert(4);
    conj.insert(89);
    conj.insert(3);
    conj.insert(243);
    conj.insert(343);
    conj.insert(13);
    //Usando un iterador mostramos los elementos del conjunto
    for(set<int>::iterator it = conj.begin(); it != conj.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    //Preguntamos si el 3 está en el conjunto
    if(conj.count(3) == 1) cout << "El 3 si está en el conjunto" << endl;
    else cout << "El 3 no está en el conjunto" << endl;

    //... segunda manera de saberlo
    if(conj.find(3) != conj.end()) cout << "El 3 si está" << endl;
    else cout << "El 3 no está en el conjunto" << endl;

    // tercer manera de saberlos usando lower_bound y upper_bound
    if(conj.lower_bound(3) != conj.upper_bound(3)) cout << "El 3 si está" << endl;
    else cout << "El 3 no está en el conjunto" << endl;
    return 0;
}
