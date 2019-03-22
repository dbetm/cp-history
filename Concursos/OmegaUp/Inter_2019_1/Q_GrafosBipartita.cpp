// A C++ program to implement greedy algorithm for graph coloring
#include <iostream>
#include <list>
// https://omegaup.com/arena/problem/Grafos-Bipartita#problems
using namespace std;

// A class that represents an undirected graph
class Graph {
	int V; 			// No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
	public:
		// Constructor and destructor
		Graph(int V) {
			this->V = V;
			adj = new list<int>[V];
		}
		~Graph() {
			delete [] adj;
		}

		// function to add an edge to graph
		void addEdge(int v, int w);

		// returns greedy coloring of the vertices
		int greedyColoring();
};

void Graph::addEdge(int v, int w) {
	//cout << "JSBjsba" << endl;
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected, therefore symetric
}

// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
int Graph::greedyColoring() {
	int result[V];
	int colors[V] = {};
	// Assign the first color to first vertex
	result[0] = 0;

	// Initialize remaining V-1 vertices as unassigned
	for (int u = 1; u < V; u++)
		result[u] = -1; // no color is assigned to u

	// A temporary array to store the available colors. True
	// value of available[cr] would mean that the color cr is
	// assigned to one of its adjacent vertices
	bool available[V];
	for (int cr = 0; cr < V; cr++)
		available[cr] = false;

	// Assign colors to remaining V-1 vertices
	for (int u = 1; u < V; u++) {
		// Process all adjacent vertices and flag their colors
		// as unavailable
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[*i] != -1)
				available[result[*i]] = true;

		// Find the first available color
		int cr;
		for (cr = 0; cr < V; cr++)
			if (available[cr] == false)
				break;

		result[u] = cr; // Assign the found color

		// Reset the values back to false for the next iteration
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[*i] != -1)
				available[result[*i]] = false;
	}

    for (int u = 0; u < V; u++) {
		colors[result[u]] = 1;
	}

    // count the different colors
	int cont = 0;
    for (int k = 0; k < V; ++k) {
    	if(colors[k] == 1) cont++;
    }
    return cont;
}

// Driver program to test above function
int main() {
    int n;
    cin >> n;
    Graph g1(n);
    char aux;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aux;
            if(aux == '1' && j >= i+1 && i < n-1)
                g1.addEdge(i, j);
        }
    }
    if(g1.greedyColoring() == 2) cout << "SI" << endl;
    else cout << "NO" << endl;
	return 0;
}
