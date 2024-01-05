#include <iostream>
#include <list>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

/* Clase para un grafo dirigido, usando una lista de adjacencia */
class Graph {
    int v; // número de vértices
    list<int> *adj; // lista de adyacencia
    bool *visitados;

    public:
        Graph(int v); // Constructor
        void addEdge(int origen, int destino);
        void BFS(int origen);
        void DFS(int origen);
        ~Graph();
};

Graph::Graph(int v) {
    this->v = v;
    this->adj = new list<int>[this->v+1];
    this->visitados = new bool[this->v+1];
    memset(this->visitados, false, sizeof(*this->visitados));
}

void Graph::addEdge(int origen, int destino) {
    this->adj[origen].push_back(destino); // agregar destino a origen
}

/* DFA cuando se trata de un grafo conectado, todos los vértices son alcanzables
desde cualquier vértice */
// Complejidad O(v + e)
void Graph::DFS(int origen) {
    this->visitados[origen] = true;
    cout << origen << endl;
    list<int>::iterator it;
    for (it = this->adj[origen].begin(); it != this->adj[origen].end(); ++it) {
        if(!this->visitados[*it]) {
            DFS(*it);
        }
    }
}

/* BGS cuando se trata de un grafo conectado
todos los vértices son alcanzables desde cada vértice. */
// Complejidad O(v + e)
void Graph::BFS(int origen) {
    //bool visitados[this->v+1];
    queue<int> cola;
    cola.push(origen);
    this->visitados[origen] = true;
    int actual;

    while(!cola.empty()) {
        actual = cola.front();
        cout << actual << endl;
        cola.pop();
        // agregamos a la cola los vértices vecinos de actual
        // que no han sido visitados
        list<int>::iterator it;
        for (it = this->adj[actual].begin(); it != this->adj[actual].end(); ++it) {
            if(!this->visitados[*it]) {
                cola.push(*it);
                this->visitados[*it] = true;
            }
        }
    }
}

Graph::~Graph() {
    delete [] visitados;
    delete [] adj;
}

int main() {
    int opcion, vertices, aristas, origen, destino;
    cout << "Vertices and aristas: ";
    cin >> vertices >> aristas;
    Graph g(vertices);

    cout << "Escribe las adyacencias (origen,destino):" << endl;

    for (int i = 0; i < aristas; i++) {
        cin >> origen >> destino;
        g.addEdge(origen, destino);
    }

    cout << "Comenzar en el vértice: ";
    cin >> origen;

    cout << "BFS = 1 o DFS = 2" << endl;
    cin >> opcion;

    if(opcion == 1) {
        cout << "Recorrido primero en amplitud (BFS - Breadth First Transversal) ";
        cout << "comenzando desde el vértice " << origen << endl;
        g.BFS(origen);
    }
    else {
        cout << "Recorrido primero en profundidad (DFS - Depth First Transversal) ";
        cout << "comenzando desde el vértice " << origen << endl;
        g.DFS(origen);
    }

    return 0;
}
