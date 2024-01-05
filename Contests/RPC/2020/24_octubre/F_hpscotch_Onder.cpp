#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
// AC
// Tags: DP, implementación
int mapa[maxn][maxn];
int n,k;
int dp[maxn][maxn];
vector<pair<int, int>> tiles[maxn * maxn];

int main() {
  cin >> n >> k;
  int ans = 0x3f3f3f3f;
  //Create an array with "infinite" values a large number
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> mapa[i][j];
      if (mapa[i][j] == 1) {
        dp[i][j] = 0;
        if (k == 1)ans = 0;
      }
      tiles[mapa[i][j]].push_back({i, j});
    }
  }
  //Construct the jumps
  for (int v = 2; v <= k; v++) {
    for (pair<int, int> &pre: tiles[v - 1]) {
      for (pair<int, int> &curr: tiles[v]) {
        //Diference between the previous one and the current one
        int distance = abs(curr.first - pre.first) + abs(curr.second - pre.second);
        dp[curr.first][curr.second] = min(dp[curr.first][curr.second],dp[pre.first][pre.second] + distance);
        if (v == k) ans = min(ans, dp[curr.first][curr.second]);
      }
    }
  }
  //If the value of the ans still is "infinite" then print -1
  cout << (ans == 0x3f3f3f3f ? -1 : ans)<<endl;
  return 0;
}
