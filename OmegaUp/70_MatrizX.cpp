#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Matriz-X#problems
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

    for (int i = m-1; i >= 0; i--) {
        if(i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                if(j % 2 == 0) cout << A[i][j] << " ";
            }
        }
    }
    cout << endl;

    return 0;
}
