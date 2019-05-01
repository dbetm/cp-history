#include <bits/stdc++.h>
// RTE
using namespace std;
#define MAX_LEN 1000
#define MAX_CHAR 75

// To store count of all character
int cnt[MAX_LEN][MAX_CHAR];

// To pre-process string from 0 to size of string
void preProcess(string s) {
    int n = s.size();
    // Initializing cnt with 0
    memset(cnt, 0, sizeof(cnt));
    // Store occurence of character i
    for(int i = 0; i < n; i++) cnt[i][s[i]-'0']++;

    // Store ocurrence i all character upto i
    // for (int i = 1; i < n; i++) {
    //     for (int j = 0; j < 75; j++) {
    //         cnt[i][j] += cnt[i-1][j];
    //     }
    // }
}

// Test if exist at least one occurence
bool findChar(int l, int r, char c) {

    return (cnt[r][(int)(c-'0')] - cnt[l][(int)(c-'0')]) != 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    preProcess(str);
    int n, l, r;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> l >> r;
        cout << findChar(l, r-1, c) << endl;
    }
    return 0;
}
