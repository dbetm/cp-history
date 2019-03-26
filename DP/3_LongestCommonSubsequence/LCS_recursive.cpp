#include <bits/stdc++.h>
// Source: GFG
// Time complexity: 0(2^n)
using namespace std;

/* A Naive recursive implementation of LCS problem */
int lcs(string, string, int, int);

int main(int argc, char const *argv[]) {
    string s1, s2;

    cout << "type 1st string: ";
    cin >> s1;

    cout << "type 2nd string: ";
    cin >> s2;

    cout << "LCS is: " << lcs(s1, s2, s1.size(), s2.size()) << endl;

    return 0;
}

int lcs(string s1, string s2, int m, int n) {
    if(m == 0 || n == 0) return 0;

    if(s1[m-1] == s2[n-1]) return 1 + lcs(s1, s2, m-1, n-1);
    else return max(lcs(s1, s2, m, n-1), lcs(s1, s2, m-1, n));
}
