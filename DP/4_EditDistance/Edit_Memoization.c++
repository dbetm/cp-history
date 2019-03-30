#include <bits/stdc++.h>
// Time Complexity: O(M * N)
// Auxiliary Space: O(M * N)
// Source: GFG
#define MAX 1000
using namespace std;

int min(int x, int y, int z) {
    return min(x, min(y, z));
}

int getMinDistance(string s1, string s2, int m, int n, int dp[][MAX]) {
    if(m == 0 || n == 0) return m + n;

    // si la llamada recursiva ha sido llamada antes, entonces,
    // solo se consulta
    if(dp[m-1][n-1] != -1) return dp[m-1][n-1];
    // si lo últtimos caracteres coinciden, nada se tiene que hacer
    // solo seguir con la recursión
    else if(s1[m-1] == s2[n-1])
        return dp[m-1][n-1] = getMinDistance(s1, s2, m-1, n-1, dp);

    // si no es el caso hacemos alguna de las 3 posibles operaciones
    else
        return dp[m-1][n-1] = 1 + min(
            getMinDistance(s1, s2, m, n-1, dp), // insertar
            getMinDistance(s1, s2, m-1, n, dp), // eliminar
            getMinDistance(s1, s2, m-1, n-1, dp)// reemplazar
        );
}

int main(int argc, char const *argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    int dp[s1.size()][MAX];

    memset(dp, -1, sizeof dp);

    cout << "Min distance edit is: " << getMinDistance(s1, s2, s1.size(), s2. size(), dp) << endl;
    return 0;
}
