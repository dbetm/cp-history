#include <iostream>
#include <map>
#include <vector>

using namespace std;
// Mapa es un contenedor asociativo que contiene pares de llaves y valores

// Programa que muestra cómo crear un mapa con otro tipo de dato que no es
// primitivo y por ende se debe implementar un comparador

bool comvec(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}

int main() {
    map<vector<int>, int, bool (*)(vector<int>, vector<int>)> map1(comvec);
    return 0;
}
