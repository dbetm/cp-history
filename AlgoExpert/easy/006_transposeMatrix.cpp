#include <bits/stdc++.h>
// solved
// tags: math, implementation, arrays
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
    /*My solution
    Time: O(n*m)
    Space: O(n*m)
    */
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans(m, vector<int>(n, 0));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            ans[j][i] = matrix[i][j];
        }
    }

    return ans;
}

int main() {
    fastIO
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix;

    for(int i = 0; i < n; ++i) {
        vector<int> row(m);
        for(int j = 0; j < m; ++j) {
            cin >> row[j];
        }
        matrix.push_back(row);
    }

    vector<vector<int>> ans = transposeMatrix(matrix);

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
