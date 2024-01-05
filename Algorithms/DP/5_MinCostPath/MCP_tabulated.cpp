#include <bits/stdc++.h>
// Geeks for Geeks
// Complexity: 0(m*n)
using namespace std;

int min(int x, int y, int z) {
    return min(x , min(y, z));
}

/* Returns cost of minimum cost path from (0,0) to (m, n) in cost[][]*/
int mcp(int m, int n, vector< vector<int> > cost) {
    int tc[m+1][n+1];
    tc[0][0] = cost[0][0];
    // First column
    for (int i = 1; i <= m; i++) tc[i][0] = tc[i-1][0] + cost[i][0];
    // First row
    for (int j = 1; j <= n; j++) tc[0][j] = tc[0][j-1] + cost[0][j];
    // Buil the opt solution
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            tc[i][j] = cost[i][j] + min(tc[i-1][j], tc[i][j-1], tc[i-1][j-1]);
        }
    }
    return tc[m][n];
}


int main(int argc, char const *argv[]) {
    int m, n;
    cout << "Type m & n: ";
    cin >> m >> n;
    vector< vector<int> > a(m);
    cout << "\nType the matrix for row: " << endl;
    for (int i = 0; i < m; i++) {
        vector <int> aux(n);
        for (int j = 0; j < n; j++) cin >> aux[j];
        a[i] = aux;
    }
    cout << "MCP is: " << mcp(m-1, n-1, a) << endl;
    return 0;
}
