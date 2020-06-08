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

    public:
        Graph(int v); // Constructor
        void addEdge(int origen, int destino);
        void BFS(int origen);
        ~Graph();
};

Graph::Graph(int v) {
    this->v = v;
    this->adj = new list<int>[this->v+1];
}

void Graph::addEdge(int origen, int destino) {
    this->adj[origen].push_back(destino); // agregar destino a origen
}

// BGS cuando se trata de un grafo conectado
// todos los vértices son alcanzables desde cada vértice.
void Graph::BFS(int origen) {
    bool visitados[this->v+1];
    memset(visitados, false, sizeof(visitados));
    queue<int> cola;
    cola.push(origen);
    visitados[origen] = true;
    int actual;

    while(!cola.empty()) {
        actual = cola.front();
        cout << actual << endl;
        cola.pop();
        // agregamos a la cola los vértices vecinos de actual
        // que no han sido visitados
        list<int>::iterator it;
        for (it = this->adj[actual].begin(); it != this->adj[actual].end(); ++it) {
            if(!visitados[*it]) {
                cola.push(*it);
                visitados[*it] = true;
            }
        }
    }
}

Graph::~Graph() {

}

int main() {
    // Graph g(6);
    // g.addEdge(1,2);
    // g.addEdge(1,3);
    // g.addEdge(2,4);
    // g.addEdge(2,5);
    // g.addEdge(3,5);
    // g.addEdge(4,6);
    // g.addEdge(4,5);
    // g.addEdge(5,6);
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Recorrido primero en amplitud (BFS - Breadth First Transversal) ";
    cout << "comenzando desde el vértice 1" << endl;

    g.BFS(2);

    return 0;
}
