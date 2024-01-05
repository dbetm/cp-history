# include <iostream>
# include <set>
# include <vector>
// Programa que muestra cómo crear un conjunto con otro tipo de dato que no
// tiene comparador por defecto.
using namespace std;

//Este es el comparador
bool comvec ( vector < int > v1 , vector < int > v2 ) {
    return v1 . size () < v2 . size () ;
}

int main () {
    //Creación de un conjunto con 'vector<int>' como Tipo_de_Dato
    set < vector < int > , bool (*) ( vector < int > , vector < int >) > conjvec (comvec);
    return 0;
}
