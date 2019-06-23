#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Matriz-de-Adyacencia
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    int arr[n][n] = {{0}};

    while(m--) {
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
