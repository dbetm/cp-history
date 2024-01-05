#include <iostream>
#include <queue>

/*
Programa sencillo que muestra el uso de la estructura de datos "cola".
*/

using namespace std;

int main() {
    int aux;
    queue<int> que;
    cout << "Primer elemento: ";
    cin >> aux;
    que.push(aux);
    cout << "Inicio y fin" << endl;
    cout << que.front() << " " << que.back() << endl;
    cout << "Segundo elemento: ";
    cin >> aux;
    que.push(aux);
    cout << "Inicio y fin" << endl;
    cout << que.front() << " " << que.back() << endl;
    cout << "Eliminamos con pop()" << endl;
    cout << "Ahora: Inicio y fin" << endl;
    cout << que.front() << " " << que.back() << endl;

    return 0;
}
