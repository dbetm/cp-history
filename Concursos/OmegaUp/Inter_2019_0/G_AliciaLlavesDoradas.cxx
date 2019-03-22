#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/aldp#problems
#define MAX 100001

using namespace std;
// Tabla hash
int A[MAX];

int main() {
    int m, p; // puertas-chapas
    int n, l; // llaves
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> p;
        A[p] = i+1;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l;
        cout << A[l] << endl;
    }
    return 0;
}
