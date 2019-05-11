#include <stdlib.h>
#include <stdio.h>
// https://omegaup.com/arena/problem/Orden-de-las-hojas#problems
typedef struct nodo {
    int valor;
    struct nodo *izq;
    struct nodo *der;
} Nodo;

// Un árbol es un nodo
typedef Nodo Arbol;

Nodo * crearNodo(int valor) {
    Nodo * nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    // Sin hijos
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
}

void insertar(Nodo ** arbol, int valor) {
    if(*arbol == NULL) *arbol = crearNodo(valor);
    else {
        int valorRaiz = (*arbol)->valor;
        if(valor < valorRaiz) { // se inserta a la izquierda
            insertar(&(*arbol)->izq, valor);
        }
        else { // se inserta a la derecha
            insertar(&(*arbol)->der, valor);
        }
    }
}

void preOrden(Nodo* arbol) {
    if(arbol != NULL) {
        printf("%d ", arbol->valor);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

int main() {
    int n;
    scanf("%d\n", &n);
    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Creamos el árbol
    Nodo *arbol = NULL;
    // Insertamos los números que se guardaron en el arreglo
    for (int i = n-1; i >= 0; i--) {
        insertar(&arbol, arr[i]);
    }
    // Imprimimos en preOrden
    preOrden(arbol);
    printf("\n");
}
