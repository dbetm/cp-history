#include <bits/stdc++.h>
// No se ha entendido completamente
using namespace std;

// Matrix Ai has dimension p[i-1]*p[i]
// for i = 1...n
int matrixChainOrder(int p[], int n) {
    /* For simplicy of the program, one extra row and one extra column are
    allocated in m[][]. 0th row and 0th column are not used.
    */
    int m[n][n];
    int i, j, k, L, q;
    /*
    m[i][j] = Minimum number of scalar multiplications needed to compute
    the matrix A[i]A[i+1]...A[j] = A[i...j] where dimension
    of A[i] is p[i-1] * p[i]
    Cost is zero when multiplying one matrix
    */
    for (i = 1; i < n; i++) m[i][i] = 0;
    // L is chain length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j];
                if(q < m[i][j]) m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

int main() {
    int n;
    cout << "Type n: ";
    cin >> n;
    int arr[n];
    cout << "Type each arr_i: " << endl;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Minimum number of multiplications is: " << matrixChainOrder(arr, n) << endl;
    return 0;
}
