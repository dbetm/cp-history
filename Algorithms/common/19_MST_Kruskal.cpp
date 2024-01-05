#include <bits/stdc++.h>
/* Minimum Spanning Tree (MST):
Problem: Select edges in a connected and undirected graph to
1. Form a tree that connects all the vertices.
2. Minimize the total edge weight of the spanning tree.

Árbol de expansión mínimo: Es un subconjunto de aristas de un grafo conectado
no-dirigido con ponderación en las aristas  que conecta todos los vértices,
sin ciclos y con el peso de aristas total mínimo posible.

Tentativa de solución:
# Usar el algoritmo de Kruskal (algoritmo greedy)
1) Sort the edges (from the lowest weight to the greatest weight).
2) Pick the sorted edges (safe, it doesn't make a cycle in the current MST)
    2.1) Use a Disjoint-set for cycle detection.
        2.1.1) Make a set for every vertex.
        2.1.2) Use the next ops. to detect cycle in Kruskal algorithm.
            2.1.2.1) UNION -> Take 2 sets and merge them in one.
            2.1.2.2) FIND -> Return a representative element for that set.

*/
using namespace std;

struct Edge {
    int v1;
    int v2;
    int weight;
    Edge(int v1, int v2, int weight): v1(v1), v2(v2), weight(weight) {}
};

class DisjointSet {
private:
    vector<int> parents;
public:
    DisjointSet(int n);
    int find(int vertex);
    void merge(int a, int b);
    ~DisjointSet();
};

DisjointSet::DisjointSet(int n): parents(n+1) {
    // make a set for each vertex (1-n)
    for (int i = 0; i < n; ++i) {
        parents[i] = i;
    }
}

int DisjointSet::find(int v) {
    return this->parents.at(v);
}

void DisjointSet::merge(int s1, int s2) {
    int a = this->find(s1);
    int b = this->find(s2);

    this->parents[b] = a;
}

DisjointSet::~DisjointSet() {
    if(!this->parents.empty()) this->parents.clear();
}

vector<Edge*> generateMST(vector<Edge*> &graph, int n) {
    vector<Edge*> ans;

    return ans;
}


int main() {
    int n, edges, a, b, weight;
    cin >> n >> edges;
    vector<Edge*> graph(edges);

    for (int i = 0; i < edges; ++i) {
        cin >> a >> b >> weight;
        graph[i] = new Edge(a, b, weight);
    }

    auto ans = generateMST(graph, n);

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i]->weight << ans[i]->v1 << ans[i]->v2 << endl;
    }

    return 0;
}

/*
CASES:
num_vertices
num_edges
    vertex_1 vertex_2 edge_weight

+ GRAPH #1
5
1 2 9
1 5 11
1 3 5
3 2 10
3 5 6
4 2 12
4 5 3

*/
