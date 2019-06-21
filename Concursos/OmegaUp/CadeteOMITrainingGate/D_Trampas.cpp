#include <bits/stdc++.h>
// No sirve
using namespace std;
#define MAX 301

char laberinto[MAX][MAX];

int minimoTrampas(int n, int m, int dp[][MAX]);
int M;
int N;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> N >> M;
    cin >> x >> y;
    x--;
    y--;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> laberinto[i][j];
        }
    }
    int dp[N][MAX];
    memset(dp, -1, sizeof dp);
    cout << minimoTrampas(x, y, dp) << endl;
    return 0;
}

int minimoTrampas(int n, int m, int dp[][MAX]) {
    cout << n << ", " << m << endl;
    cin.get();
    if(n < 0 || m < 0 || m >= M || n >= N) return INT_MAX;
    else if(laberinto[n][m] == '#') return dp[n][m] = INT_MAX;
    else if(laberinto[n][m] == 'S') return 0;
    else if(dp[n][m] != -1) return dp[n][m];
    else {
        int val = 0;
        if(laberinto[n][m] == 'x') val = 1;
        int arriba = minimoTrampas(n-1, m, dp);
        cout << "Arriba " << arriba << endl;
        int izquierda = minimoTrampas(n, m-1, dp);
        cout << "Izquierda " << izquierda << endl;
        int abajo = minimoTrampas(n+1, m, dp);
        cout << "Abajo " << izquierda << endl;
        int derecha = minimoTrampas(n, m+1, dp);
        cout << "Derecha " << izquierda << endl;
        dp[n][m] = val + min(arriba, min(min(abajo, izquierda), derecha));
        cout << dp[n][m] << endl;
        return dp[n][m];
    }

}
