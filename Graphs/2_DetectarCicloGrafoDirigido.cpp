#include <bits/stdc++.h>

using namespace std;


class Graph {
    private:
        int v;
        list<int> *adj;
        bool *visitados;
        bool *recursiveStack;
        bool detectCycleUtil(int v);
    public:
        Graph(int v);
        void addEdge(int origen, int dest);
        bool detectCycle();
        ~Graph();
};

Graph::Graph(int v) {
    this->v = v;
    this->adj = new list<int>[this->v+1];
    this->visitados = new bool[this->v+1];
    this->recursiveStack = new bool[this->v+1];
}

void Graph::addEdge(int origen, int dest) {
    this->adj[origen].push_back(dest);
}

bool Graph::detectCycle() {

    // Inicializar el arreglo de visitados
    memset(this->visitados, false, sizeof(*this->visitados));
    memset(this->recursiveStack, false, sizeof(*this->recursiveStack));

    for (int i = 0; i < this->v; i++) {
        if(detectCycleUtil(i)) return true;
    }

    return false;
}

bool Graph::detectCycleUtil(int v) {
    if(this->visitados[v] == false) {
        this->visitados[v] = true;
        this->recursiveStack[v] = true;

        // Recorremos de forma recursiva para el actual vértice v
        list<int>::iterator it;
        for(it = this->adj[v].begin(); it != this->adj[v].end(); ++it) {
            if(!this->visitados[*it] && detectCycleUtil(*it)) return true;
            else if(this->recursiveStack[*it]) return true;
        }
    }
    this->recursiveStack[v] = false; // quitar el vértice de la recursión
    return false;
}

Graph::~Graph() {
    delete [] this->adj;
    delete [] this->visitados;
    delete [] this->recursiveStack;
}


int main() {
    int vertices, aristas, origen, destino;
    cout << "Vertices and aristas: ";
    cin >> vertices >> aristas;
    Graph g(vertices);

    cout << "Escribe las adyacencias (origen,destino):" << endl;

    for (int i = 0; i < aristas; i++) {
        cin >> origen >> destino;
        g.addEdge(origen, destino);
    }

    cout << "Hay ciclo?" << endl;
    cout << g.detectCycle() << endl;

    return 0;
}
