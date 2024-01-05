#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, aristas;
    cin >> n >> aristas;
    int A[n][n] = {};
    int x, y;
    for (int i = 0; i < aristas; i++) {
        cin >> x >> y;
        A[x][y] = 1;
        A[y][x] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
