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
    priority_queue <int> pq; // max Heap
    // Creando un Min Heap, la prioridad es tener los menores
    priority_queue <int, vector<int>, greater<int>> pq2;
    // construyendo desde un iterable (array o vector)
    int array[] = {1, 8, 0, 34, 7, 8};
    int n = 6;
    priority_queue <int, vector<int>, greater<int>> pq3(array, array+n);

    // Agregar a la cola de prioridad los elementos
    cout << "100, 10, 20, 100, 70 y 2000" << endl;
    pq.push(100);
    pq.push(10);
    pq.push(20);
    pq.push(100);
    pq.push(70);
    pq.push(2000);
    // Si la cola de prioridad no está vacía
    if(!pq.empty()) {
        // Rescatamos el top
        int a = pq.top(); // 0(1)
        // La eliminación no es cte, 0(log N)
        pq.pop();
        cout << "Se eliminó: " << a << "\n";
    }
    // salida => 100 100 70 20 10
    return 0;
}
