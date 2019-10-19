#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
// Complexity time O(n^2)
using namespace std;
// SRC: Geeks For Geeks

// Representación de la caja
struct Box {
    int altura, ancho, profundidad;
};

/*void qsort(void* base, size_t num, size_t size,int (*compar)(const void*,const void*));
-> Sorts the num elements of the array pointed to by base,
each element size bytes long, using the compar function to determine the order.

The sorting algorithm used by this function compares pairs of elements
by calling the specified compar function with pointers to them as argument.
*/

int comparar(const void *a, const void *b) {
    return ( (*(Box *)b).profundidad * (*(Box *)b).ancho) -
        ( (*(Box *)a).profundidad * (*(Box *)a).ancho);
}

/* Retorna la altura de la pila más alta que puede ser formada con las cajas
dadas.
*/
int maxStackHeight(Box arr[], int n) {
    /* Crear un arreglo para todas las rotaciones de las cajas dadas.
    Por ejemplo, para la caja {1,2,3}, consideramos 3 instancias
    {{1,2,3}, {3,2,1}, {2,1,3}}
    */
    Box rot[n+n+n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        // Copiar la caja original
        rot[index].altura = arr[i].altura;
        rot[index].profundidad = max(arr[i].ancho, arr[i].profundidad);
        rot[index].ancho = min(arr[i].ancho, arr[i].profundidad);
        index++;

        // Primera rotación de la caja
        rot[index].altura = arr[i].ancho;
        rot[index].profundidad = max(arr[i].altura, arr[i].profundidad);
        rot[index].ancho = min(arr[i].altura, arr[i].profundidad);
        index++;

        // Segunda rotación de la caja
        rot[index].altura = arr[i].profundidad;
        rot[index].profundidad = max(arr[i].altura, arr[i].ancho);
        rot[index].ancho = min(arr[i].altura, arr[i].ancho);
        index++;
    }
    // Ahora el número de cajas es 3*n
    n *= 3;
    qsort(rot, n, sizeof(rot[0]), comparar);

    // Imprimir cada caja con sus tres posibles rotaciones
    // En orden descendente, según la base
    // for (int i = 0; i < n; i++ )
    //     printf("%d x %d x %d\n", rot[i].altura, rot[i].ancho, rot[i].profundidad);

    // Inicializar los valores del MSH para todos los índices, casos base
    int msh[n];
    for (int i = 0; i < n; i++) {
        msh[i] = rot[i].altura;
    }

    // Hacemos tabulación
    /* Puede pasar:
        1) La caja anterior tiene una base mayor:

        2) La caja anterior no tiene una base mayor:
    */
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(rot[i].ancho < rot[j].ancho && rot[i].profundidad < rot[j].profundidad) {
                msh[i] = max(msh[i], msh[j] + rot[i].altura);
            }
        }
    }

    // Retornamos el valor máximo
    return *max_element(msh, msh+n);
}


int main() {
    int n;
    cout << "Escribe el número de elementos: ";
    cin >> n;
    Box cajas[n];
    cout << "Escribe las tripletas por cada caja (alto, profundidad, ancho)" << endl;

    for (int i = 0; i < n; i++) {
        cin >> cajas[i].altura >> cajas[i].profundidad >> cajas[i].ancho;
    }

    cout << "La pila de máxima altura es: " << maxStackHeight(cajas, n) << endl;

    return 0;
}
