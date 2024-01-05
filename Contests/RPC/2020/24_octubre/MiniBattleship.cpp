#include<bits/stdc++.h>
// AC
using ll = long long;
using namespace std;
const int maxn = 10;
int n, k;
char mapa[maxn][maxn];
bool grid[maxn][maxn];
int s[maxn];

int solution(int m) {
  if (m > k) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (mapa[i][j] == 'O' && !grid[i][j]) {
          return 0;
        }
      }
    }
    return 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i + s[m] - 1 <= n) {
        bool suc = true;
        for (int k = i; k <= i + s[m] - 1; k++) {
          if (grid[k][j] || mapa[k][j] == 'X') {
            suc = false;
            break;
          }
        }
        if (suc) {
          for (int k = i; k <= i + s[m] - 1; k++) {
            grid[k][j] = 1;
          }
          ans += solution(m+1);
          for (int k = i; k <= i + s[m] - 1; k++) {
            grid[k][j] = 0;
          }
        }
      }
      if (s[m] == 1) continue;
      if (j + s[m] - 1 <= n) {
        bool suc = true;
        for (int k = j; k <= j + s[m] - 1; k++) {
          if (grid[i][k] || mapa[i][k] == 'X') {
            suc = false;
            break;
          }
        }
        if (suc) {
          for (int k = j; k <= j + s[m] - 1; k++) {
            grid[i][k] = 1;
          }
          ans += solution(m + 1);
          for (int k = j; k <= j + s[m] - 1; k++) {
            grid[i][k] = 0;
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> (mapa[i] + 1);
  }
  memset(grid, 0, sizeof(grid));
  for (int i = 1; i <= k; i++) {
    cin >> s[i];
  }
  cout << solution(1) << endl;
  return 0;
}
