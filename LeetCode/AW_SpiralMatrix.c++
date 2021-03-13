#include <bits/stdc++.h>
// https://leetcode.com/problems/spiral-matrix/
// Tag(s): Implementation
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
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> ans;
        if(m == 0) return ans;
        int n = matrix[0].size();
        if(n == 0) return ans;

        int total = m * n, count = 0;
        int startRow = 0, endRow = m-1, startCol = 0, endCol = n-1;

        while(startRow <= endRow and startCol <= endCol) {
            // Top row (start row)
            for (int i = startCol; i <= endCol; ++i) {
                ans.push_back(matrix[startRow][i]);
                ++count;
            }
            ++startRow;
            if(count == total) break;;

            // Right column (end col)
            for (int i = startRow; i <= endRow; ++i) {
                ans.push_back(matrix[i][endCol]);
                ++count;
            }
            --endCol;
            if(count == total) break;

            // Bottom row
            for (int i = endCol; i >= startCol; --i) {
                ans.push_back(matrix[endRow][i]);
                ++count;
            }
            --endRow;
            if(count == total) break;

            // Left column (start col)
            for (int i = endRow; i >= startRow; --i) {
                ans.push_back(matrix[i][startCol]);
                ++count;
            }
            if(count == total) break;
            ++startCol;
        }

        return ans;
    }
};

int main() {
    fastIO
    int m, n, aux;
    Solution sol;

    cin >> m >> n;
    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> aux;
            matrix[i].push_back(aux);
        }
    }

    vector<int> ans = sol.spiralOrder(matrix);
    int len = ans.size();
    for (int i = 0; i < len-1; ++i) {
        cout << ans[i] << " ";
    }
    cout << ans[len-1] << endl;

	return 0;
}
