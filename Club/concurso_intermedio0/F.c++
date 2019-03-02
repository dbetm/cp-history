#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/chocolates#problems
#define MAX 1000

bool visitados[MAX][MAX];
int ganancias[MAX][MAX];
int precios[MAX];

using namespace std;

int getMaxGanancia(int, int, int);

int main() {
    unsigned int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) cin >> precios[i];
    // getMaxGanancia(indice_izq_chocolate, indice_der_chocolate, primer_dia)
    cout << getMaxGanancia(0, n-1, 1) << endl;;
    return 0;
}

// precios [l, l+1, l+2, ..., r-2, r-1, r]

// l -> left, r -> rigth, dia -> day
int getMaxGanancia(int l, int r, int dia) {
    if(visitados[l][r]) return ganancias[l][r];
    visitados[l][r] = true;
    int maxGanancia;
    if(l == r) maxGanancia = precios[l]*dia;
    else
        maxGanancia = max(getMaxGanancia(l+1, r, dia+1) + precios[l]*dia,
            getMaxGanancia(l, r-1, dia+1) + precios[r]*dia);
    return ganancias[l][r] = maxGanancia;
}
