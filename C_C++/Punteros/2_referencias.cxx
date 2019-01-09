#include <iostream>
/* Una referencia es otra forma de acceder a un dato, una especie de alias.
Cualquier operacion sobre una referencia afectara  a ese dato al que
hace referencia */
using namespace std;

int main() {
    // Definimos un dato y su referencia
    int numero;
    int &referenciaNumero = numero;
    cout << "Vamos a ver qué pasa si le asignamos un dato: " << "\n";
    numero = 42;
    // Los dos muestran el mismo valor ;)
    cout << "Número: " << numero << "\n";
    cout << "Referecia número: " << referenciaNumero << "\n";

    // ...y la misma dirección de memoria
    cout << "Dirección número: " << &numero << "\n";
    cout << "Dirección de referecia número: " << &referenciaNumero << "\n";
    cout << "The end" << "\n";
    return 0;
}
