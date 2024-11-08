#include <bits/stdc++.h>
// https://leetcode.com/problems/max-area-of-island/
// Tag(s): DFS, implementation, arrays
using namespace std;

int explore(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    if(i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0) return ans;

    grid[i][j] = 0;
    ans = 1;
    // right
    ans += explore(grid, i, j-1);
    // left
    ans += explore(grid, i, j+1);
    // up
    ans += explore(grid, i-1, j);
    // down
    ans += explore(grid, i+1, j);

    return ans;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(grid[i][j] == 1) {
                int ans = explore(grid, i, j);
                maxArea = max(ans, maxArea);
            }
        }
    }

    return maxArea;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << maxAreaOfIsland(grid) << endl;

    return 0;
}
