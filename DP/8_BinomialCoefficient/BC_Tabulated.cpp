#include <bits/stdc++.h>
// Time complexity: O(n*k)
// Auxiliary space: O(n*k)
using namespace std;

int bc(int n, int k) {
    int C[n+1][k+1];

    // Calcular el valor del coeficiente binomial de manera ascendente
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            // Casos base
            if(j == 0 || j == i) C[i][j] = 1;
            else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
    return C[n][k];
}

int main() {
    int n, k;
    cout << "Type n: ";
    cin >> n;
    cout << "Type k: ";
    cin >> k;
    cout << "The binomial coefficient is: " << bc(n, k) << endl;
    return 0;
}
