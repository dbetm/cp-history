#include <bits/stdc++.h>
// Parcialmente correcta
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    int64_t A[n][n];
    for (int64_t i = 0; i < n; i++)
        for (int64_t j = 0; j < n; j++) cin >> A[i][j];

    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = 0; j < n-1; j++) cout << A[j][i] << " ";
        cout << A[n-1][i] << endl;
    }

    return 0;
}
