#include <iostream>
// https://omegaup.com/arena/problem/Matriz-Semejante-Diagonal#problems
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int numDiagPrincipal = a[0][0];
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == j && numDiagPrincipal != a[i][j]) {
                cout << "NO" << endl;
                i = n;
                flag = false;
                break;
            }
            else if(a[i][j] != a[j][i]) {
                cout << "NO" << endl;
                i = n;
                flag = false;
                break;
            }
        }
    }

    if(flag) cout << "SI" << endl;

    return 0;
}
