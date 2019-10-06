#include <bits/stdc++.h>

using namespace std;

bool findPattern(vector<string> matrix, vector<string> pattern, int R, int C, int r, int c);

int main() {
    int t, R, C, r, c, i;
    string row;
    cin >> t;
    while(t--) {
        cin >> R >> C;
        vector<string> matrix(R);
        for (i = 0; i < R; i++) cin >> matrix[i];
        cin >> r >> c;
        vector<string> pattern(r);
        for (i = 0; i < r; i++) cin >> pattern[i];
        cout << ((findPattern(matrix, pattern, R, C, r, c)) ? "YES" : "NO") << endl;
    }
    return 0;
}

bool findPattern(vector<string> matrix, vector<string> pattern, int R, int C, int r, int c) {
    bool ans = false;
    int area = r * c, aux;
    for (int i = 0; i < R-r+1; i++) {
        for (int j = 0; j < C-c+1; j++) {
            aux = 0;
            for (int k = 0; k < r; k++) {
                for (int l = 0; l < c; l++) {
                    if(matrix[i+k][j+l] == pattern[k][l]) aux++;
                    else {
                        k = r;
                        break;
                    }
                }
            }
            if(aux == area) {
                i = R;
                ans = true;
                break;
            }
        }
    }

    return ans;
}
