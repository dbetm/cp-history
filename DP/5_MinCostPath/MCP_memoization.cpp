#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int min(int x, int y, int z) {
    return min(x , min(y, z));
}

/* Returns cost of minimum cost path from (0,0) to (m, n) in cost[][]*/
int mcp(int m, int n, vector< vector <int> > cost, int dp[][MAX]) {
    if(m < 0 || n < 0) return INT_MAX;
    else if(m == 0 && n == 0) return cost[m][n];
    else if(dp[m][n] != -1) return dp[m][n];
    else
        return dp[m][n] = cost[m][n] + min(mcp(m-1, n-1, cost, dp), mcp(m-1, n, cost, dp), mcp(m, n-1, cost, dp));
}


int main(int argc, char const *argv[]) {
    int m, n;
    cout << "Type m & n: ";
    cin >> m >> n;
    vector< vector<int> > a(m);
    int dp[m][MAX];
    memset(dp, -1, sizeof dp);

    cout << "\nType the matrix for row: " << endl;
    for (int i = 0; i < m; i++) {
        vector <int> aux(n);
        for (int j = 0; j < n; j++) cin >> aux[j];
        a[i] = aux;
    }
    cout << "MCP is: " << mcp(m-1, n-1, a, dp) << endl;
    return 0;
}
