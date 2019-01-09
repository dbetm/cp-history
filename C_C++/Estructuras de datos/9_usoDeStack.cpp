#include <iostream>
#include <stack>

/*
Programa sencillo que muestra el uso de la estructura de datos "pila".
*/

using namespace std;

int main(int argc, char const *argv[]) {
    int aux;
    stack<int> stc;
    cout << "Primer elemento: ";
    cin >> aux;
    stc.push(aux);
    cout << "Segundo elemento: ";
    cin >> aux;
    stc.push(aux);
    cout << "Tercer elemento: ";
    cin >> aux;
    stc.push(aux);
    cout << "El elemento que está en el tope es: ";
    cout << stc.top() << "\n";
    cout << "Se ha borrado el anterior valor" << endl;
    stc.pop();
    cout << "El elemento que está en el tope es: ";
    cout << stc.top() << "\n";
    return 0;
}
