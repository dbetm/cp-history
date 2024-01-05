#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cout << "Type string: ";
    cin >> s;
    vector<int> pi = prefix_function(s);
    int n = (int)pi.size();
    // Values for pi[i]
    for (int i = 0; i < n; i++) {
        cout << "p[" << i << "] = " << pi[i] << endl;
    }
    return 0;
}
