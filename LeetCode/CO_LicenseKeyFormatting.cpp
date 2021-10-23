#include <bits/stdc++.h>
// https://leetcode.com/problems/license-key-formatting/
// Tag(s): strings, implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

string licenseKeyFormatting(string s, int k) {
    string ans = "", aux = "";
    int n = s.size(), i;

    int r = 0;
    while(r < n and s[r] == '-') {
        ++r;
    }

    for (i = n-1; i >= r; --i) {
        if(s[i] != '-') aux += toupper(s[i]);

        if((int)aux.size() == k) {
            ans += aux + ((i == r) ? "" : "-");
            aux = "";
        }
    }
    ans += aux;

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    fastIO
    string s;
    int k;
    cin >> s;
    cin >> k;

    cout << licenseKeyFormatting(s, k) << endl;

	return 0;
}
