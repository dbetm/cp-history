#include <bits/stdc++.h>
// Geeks for Geeks
// Complexity: Exponential
using namespace std;

int min(int x, int y, int z) {
    return min(x , min(y, z));
}

/* Returns cost of minimum cost path from (0,0) to (m, n) in cost[][]*/
int mcp(int m, int n, vector< vector<int> > cost) {
    if(m < 0 || n < 0) return INT_MAX;
    else if(m == 0 && n == 0) return cost[m][n];
    else
        return cost[m][n] + min(mcp(m-1, n-1, cost), mcp(m-1, n, cost), mcp(m, n-1, cost));
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
