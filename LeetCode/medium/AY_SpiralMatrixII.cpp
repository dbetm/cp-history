#include <bits/stdc++.h>
// https://leetcode.com/problems/spiral-matrix-ii/
// Tag(s): Arrays, implementation
using namespace std;

#define watch(x) cout << (#x) << " es " << x << endl;

class Solution {
    public:
        Solution();
        vector<vector<int>> generateMatrix(int n);
        ~Solution();
};

Solution::Solution() {}

vector<vector<int>> Solution::generateMatrix(int n) {
    int cont = 0;
    int n2 = n * n;
    /*
    0: right
    1: down
    2: left
    3: up
    */
    int direction = 0;

    vector<vector<int>> ans(n, vector<int>(n, -1));
    int i = 0, j = -1;

    while(cont++ <= n2) {
        if(direction == 0) {
            j++;
            while(j < n and ans[i][j] == -1) {
                ans[i][j] = cont;
                if(j+1 < n and ans[i][j+1] == -1) {
                    cont++;
                    j++;
                }
            }
        }
        else if(direction == 1) {
            i++;
            while(i < n and ans[i][j] == -1) {
                ans[i][j] = cont;
                if(i+1 < n and ans[i+1][j] == -1) {
                    cont++;
                    i++;
                }
            }
        }
        else if(direction == 2) {
            j--;
            while(j >= 0 and ans[i][j] == -1) {
                ans[i][j] = cont;
                if(j-1 >= 0 and ans[i][j-1] == -1) {
                    cont++;
                    j--;
                }
            }
        }
        else {
            i--;
            while(i >= 0 and ans[i][j] == -1) {
                ans[i][j] = cont;
                if(i-1 >= 0 and ans[i-1][j] == -1) {
                    cont++;
                    i--;
                }
            }
        }

        ++direction;
        direction = direction % 4;
    }

    return ans;
}

Solution::~Solution() {}

int main() {
    int n;
    Solution sol;
    cin >> n;

    vector<vector<int>> ans = sol.generateMatrix(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
