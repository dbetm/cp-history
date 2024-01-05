#include <bits/stdc++.h>
/*
    Una cola de prioridades es un tipo de dato abstracto similar a una cola en la
    que los elementos tienen adicionalmente, una prioridad asignada.
    ​En una cola de prioridades un elemento con mayor prioridad será desencolado
    antes que un elemento de menor prioridad. Si dos elementos tienen la misma
    prioridad, se desencolarán siguiendo el orden de cola.
*/
using namespace std;

int main() {
    priority_queue <int> pq;
    // Agregar a la cola de prioridad los elementos
    cout << "100, 10, 20, 100, 70 y 2000" << endl;
    pq.push(100);
    pq.push(10);
    pq.push(20);
    pq.push(100);
    pq.push(70);
    pq.push(2000);
    if(pq.empty()) cout << "La cola de prioridad está vacía" << endl;
    else {
        cout << "La cola de prioridad lleva ";
        cout << pq.size() << " elementos\n";
    }
    return 0;
}
