#include <bits/stdc++.h>

using namespace std;

int lps(string seq) {
    int n = seq.size();
    int L[n][n];

    // Caso base
    for (int i = 0; i < n; i++) L[i][i] = 1;

    // Construimos la tabla, observar que la matriz triangular inferior no es usada
    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n-cl+1; i++) {
            int j = i+cl-1;
            if(seq[i] == seq[j] && cl == 2) L[i][j] = 2;
            else if(seq[i] == seq[j]) L[i][j] = L[i+1][j-1] + 2;
            else L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }

    return L[0][n-1];
}

int main() {
    string sequence;
    cin >> sequence;
    cout << lps(sequence) << endl;
    return 0;
}
