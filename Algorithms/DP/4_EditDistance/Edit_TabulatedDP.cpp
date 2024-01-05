#include <bits/stdc++.h>
// Time Complexity: O(m x n)
// Auxiliary Space: O(m x n)
// Source: GFG
using namespace std;
// minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
int min(int x, int y, int z) {
    return min(x, min(y, z));
}

int getMinDistance(string s1, string s2, int m, int n) {
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if(i == 0) dp[i][j] = j; // sería insertar j caracteres
            else if(j == 0) dp[i][j] = i; // sería eliminar j caracteres
            // Son iguales, nada que hacer
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Min distance edit is: " << getMinDistance(s1, s2, s1.size(), s2. size()) << endl;
    return 0;
}
