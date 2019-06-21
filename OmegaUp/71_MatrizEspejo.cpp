#include <iostream>
// https://omegaup.com/arena/problem/Matriz-Espejo#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    int A[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];

    for (int i = 0; i < m; i++) {
        for (int j = n-1; j >= 0; j--) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
