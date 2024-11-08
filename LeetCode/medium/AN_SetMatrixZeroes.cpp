#include <bits/stdc++.h>
// https://leetcode.com/problems/set-matrix-zeroes/
// Tag(s): Implementación
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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;

        int n = matrix[0].size();
        if(n == 0) return;

        bool hasFirstRowZeroes = false, hasFirstColZeroes = false;

        // Search zeroes in first row
        for (int j = 0; j < n; ++j) {
            if(matrix[0][j] == 0) {
                hasFirstRowZeroes = true;
                break;
            }
        }

        // Search zeroes in first column
        for (int i = 0; i < m; ++i) {
            if(matrix[i][0] == 0) {
                hasFirstColZeroes = true;
                break;
            }
        }

        // Save info of cols and rows with zeros in first col and first row.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Propagate zeros from first row
        for (int j = 1; j < n; ++j) {
            if(matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Propagate zeros from first column
        for (int i = 1; i < m; ++i) {
            if(matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Update first row
        if(hasFirstRowZeroes) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Update first column
        if(hasFirstColZeroes) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    fastIO
    Solution sol;
    int m, n, aux;
    cin >> m >> n;
    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> aux;
            matrix[i].push_back(aux);
        }
    }

    sol.setZeroes(matrix);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
