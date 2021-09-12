#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

class Solution {
private:
    void explore(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '0') return;

        int m = grid.size();
        int n = grid[0].size();

        grid[i][j] = '0';
        // up
        if((i-1) >= 0 and grid[i-1][j] == '1')
            return this->explore(grid, i-1, j);
        // down
        if((i+1) < m and grid[i+1][j] == '1')
            return this->explore(grid, i+1, j);
        // left
        if((j-1) >= 0 and grid[i][j-1] == '1')
            return this->explore(grid, i, j-1);
        // right
        if((j+1) < n and grid[i][j+1] == '1')
            return this->explore(grid, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    ans++;
                    this->explore(grid, i, j);
                }
            }
        }

        return ans;
    }
};

int main() {
    fastIO
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.numIslands(grid) << endl;

	return 0;
}
