#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define INF 1000001
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

void init(int n);
void displayGraph(int n);
void floyWarshall(int n);

vector < vector<int64_t> > graph;

int main() {
	fastIO();
    int n, m;
    int x, y;
    int64_t weight;
    int queries;
    int src, dest;

    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> weight;
        graph[x-1][y-1] = weight;
    }

    //displayGraph(n);
    floyWarshall(n);
    cin >> queries;
    while(queries--) {
        cin >> src >> dest;
        src--;
        dest--;
        if(graph[src][dest] == INF) cout << -1 << endl;
        else cout << graph[src][dest] << endl;
    }

	return 0;
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        vector<int64_t> aux(n);
        for (int j = 0; j < n; j++) {
            aux[j] = (i == j) ? 0 : INF;
        }
        graph.push_back(aux);
    }
}

void displayGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(graph[i][j] == INF) cout << "INF ";
            else cout << graph[i][j] << "  ";
        }
        cout << endl;
    }
}

void floyWarshall(int n) {
    for (int k = 0; k < n; k++) {
        // Seleccionar cada vértice como origen (src)
        for (int i = 0; i < n; i++) {
            // Seleccionar cada destino al que puede se puede llegar desde el src
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
