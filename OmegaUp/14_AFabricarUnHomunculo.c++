#include <bits/stdc++.h>
using namespace std;
// Tiempo límite excedido
int target;

int buscar(vector<int> &A, int min, int max) {
    int guess = (min + max) / 2;
    if(min > max) return 0;
    else if(A[guess] == target) return 1;
    else if(A[guess] < target) min = guess + 1;
    else max = guess - 1;
    return buscar(A, min, max);
}

int main() {
    // Faster I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, i;
    cin >> n;
    vector<int> A(n);

    for (i = n-1; i >= 0; --i) cin >> A[i];
    sort(A.begin(), A.end());

    cin >> m;
    for (i = m-1; i >= 0; --i) {
        cin >> target;
        if(buscar(A, 0, n-1)) cout << "SI" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
