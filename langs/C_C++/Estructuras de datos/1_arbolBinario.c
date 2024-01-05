#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo* izqdo;
    struct nodo* dcho;
} Nodo;

// Un árbol es un nodo
typedef Nodo Arbol;

Nodo* CrearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izqdo = nuevoNodo->dcho = NULL;
    return nuevoNodo;
}

void DestruirNodo(Nodo* nodo) {
    nodo->izqdo = nodo->dcho = NULL;
    free(nodo);
}

void Insertar(Nodo** arbol, int valor) {
    //Nodo* nuevoNodo = CrearNodo(valor);
    if(*arbol == NULL) {
        *arbol = CrearNodo(valor);
    }
    else {
        int valorRaiz = (*arbol)->valor;
        if(valor < valorRaiz)
            Insertar(&(*arbol)->izqdo, valor);
        else
            Insertar(&(*arbol)->dcho, valor);
    }
}

int Existe(Nodo* arbol, int valor) {
    if(arbol == NULL) return 0;
    else if(arbol->valor == valor) return 1;
    else if(valor < arbol->valor) return Existe(arbol->izqdo, valor);
    else return Existe(arbol->dcho, valor);
}

void DeterminarExistencia(Nodo* arbol, int valor) {
    if(Existe(arbol, valor)) { // se retorna un 1
        printf("El nodo %d existe en el árbol\n", valor);
    }
    else { // se retorna un 0
        printf("El nodo %d NO existe en el árbol\n", valor);
    }
}

void Preorden(Nodo* arbol) {
    if(arbol == NULL) {
        printf(" NHijo ");
    }
    else {
        printf("( %d ", arbol->valor);
        Preorden(arbol->izqdo);
        Preorden(arbol->dcho);
        printf(" ) ");
    }
}

void Inorden(Nodo* arbol) {
    if(arbol == NULL) printf(" - ");
    else {
        printf(" ( ");
        Inorden(arbol->izqdo);
        printf(" %d ", arbol->valor);
        Inorden(arbol->dcho);
        printf(" ) ");
    }
}

void Postorden(Nodo* arbol) {
    if(arbol == NULL) printf(" - ");
    else {
        printf(" ( ");
        Postorden(arbol->izqdo);
        Postorden(arbol->dcho);
        printf(" %d )", arbol->valor);
    }
}

int main(int argc, char const *argv[]) {
    Nodo *arbol = NULL;
    Insertar(&arbol, 5);
    Insertar(&arbol, 10);
    Insertar(&arbol, 4);
    Insertar(&arbol, 9);
    Insertar(&arbol, 15);
    DeterminarExistencia(arbol, 10);
    DeterminarExistencia(arbol, 3);
    DeterminarExistencia(arbol, 9);
    Preorden(arbol);
    printf("\n");
    Inorden(arbol);
    printf("\n");
    Postorden(arbol);
    printf("\n");
    return 0;
}
