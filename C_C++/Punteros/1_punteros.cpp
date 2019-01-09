#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[]) {
    int* puntero1;
    int a = 54;
    puntero1 = &a;

    cout << "Su dirección es: " << &puntero1 << endl;
    cout << "Otra dirección: " << puntero1 << endl;
    cout << "El contenido de la variable a la que apunta es: " << *puntero1 << endl;

    return 0;
}
