#include <bits/stdc++.h>
using namespace std;

#define MAX 404
int A[MAX][MAX];
bool visitados[MAX][MAX];
pair <int, int> tupla;
int n, m;

pair <int, int> procesar();
bool buscar(int i, int j);

string rayos[] = {"agua", "montana", "pastizal"};

int main() {
    int q, x, y;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        if(A[x-1][y-1] == 3) {
            tupla.first = x-1;
            tupla.second = y-1;
            pair <int, int> actual = procesar();
            cout << "(" << actual.first+1 << "," << actual.second+1 << ")" << endl;
        }
	else cout << rayos[A[x-1][y-1]] << endl;
    }

    return 0;
}

pair <int, int> procesar() {
    pair <int, int> coordenada;
    memset(visitados, false, sizeof visitados);
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if(buscar(i, j)) {
                coordenada.first = i;
                coordenada.second = j;
                i = -1;
                break;
            }
        }
    }
    return coordenada;
}

bool buscar(int i, int j) {
    if(visitados[i][j] || A[i][j] != 3) return false;
    visitados[i][j] = true;
    if(i == tupla.first && j == tupla.second) return true;

    bool ans = false;
    if(i+1 < n && A[i+1][j] == 3) ans = buscar(i+1, j);
    if(j+1 < m && A[i][j+1] == 3 && !ans) ans = buscar(i, j+1);
    if(j-1 >= 0 && A[i][j-1] == 3 && !ans) ans = buscar(i, j-1);
    if(i-1 >= 0 && A[i-1][j] == 3 && !ans) ans = buscar(i-1, j);

    return ans;
}
