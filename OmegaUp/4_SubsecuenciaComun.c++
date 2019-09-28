#include <bits/stdc++.h>
// Parcialmente correcta
using namespace std;

void eraseSubStr(string &mainStr, const string &toErase) {
	// Search for the substring in string
	size_t pos = mainStr.find(toErase);

	if (pos != string::npos) {
		// If found then erase it from string
		mainStr.erase(pos, toErase.length());
	}
}

string lcs(string s1, string s2, int m, int n, string inter) {
    int L[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) L[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) L[i][j] = L[i-1][j-1] + 1;
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    //int index = L[m][n];
    int i = m, j = n;
    string lcs = "";

    while (i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            lcs += s1[i-1];
            i--;
            j--;
        }
        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    if(lcs.empty()) return "0";
    reverse(lcs.begin(), lcs.end());
    eraseSubStr(lcs, inter);
    if(lcs.empty() || lcs.size() == 0) return "0";
    return lcs;
}

int main(int argc, char const *argv[]) {
    string s1, s2, inter;
    cin >> s1 >> s2 >> inter;
    cout << lcs(s1, s2, s1.size(), s2.size(), inter) << endl;
    return 0;
}
