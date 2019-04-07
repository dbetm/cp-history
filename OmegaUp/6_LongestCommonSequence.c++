#include <bits/stdc++.h>
using namespace std;
// https://omegaup.com/arena/problem/Longest-Common-Subsequence#problems
// Programación dinámica
int lcs(string, string, int, int);

int main(int argc, char const *argv[]) {
    string s1, s2;

    cin >> s1;
    cin >> s2;
    cout << lcs(s1, s2, s1.size(), s2.size()) << endl;
    return 0;
}

// Método tabulado
int lcs(string s1, string s2, int m, int n) {
    int L[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) L[i][j] = 0;
            else if (s1[i-1] == s2[j-1]) L[i][j] = L[i-1][j-1] + 1;
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    return L[m][n];
}
