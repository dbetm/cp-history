#include <bits/stdc++.h>

using namespace std;

vector<int> getPi(string s);
vector<int> countNumberOfOcurrencesEachPrefix(vector<int> pi);

int main() {
    string s;
    cout << "Type string: ";
    cin >> s;
    vector<int> pi = getPi(s);
    vector<int> ans = countNumberOfOcurrencesEachPrefix(pi);

    int n = (int)ans.size();
    for (int i = 1; i < n; i++) {
        cout << s.substr(0, i) << " appears " << ans[i] << " time(s)." << endl;
    }

    return 0;
}

vector<int> countNumberOfOcurrencesEachPrefix(vector<int> pi) {
    int n = (int)pi.size();
    vector <int> ans(n+1);
    /* Here for each value of the prefix function we first count how many
    times it occurs in the array  π */
    for (int i = 0; i < n; i++) ans[pi[i]]++;
    /* if we know that the length prefix i appears exactly ans[i] times, then
    this number must be added to the number of occurrences of its longest suffix
    that is also a prefix*/
    for (int i = n-1; i > 0; i--) {
        ans[pi[i-1]] += ans[i];
        cout << ans[pi[i-1]] << endl;
    }
    /* We need to add 1 to each result, since we also need to
    count the original prefixes also.*/
    for (int i = 0; i < n; i++) ans[i]++;

    return ans;
}

vector<int> getPi(string s) {
    int n = (int)s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[j] == s[i]) j++;
        pi[i] = j;
    }
    return pi;
}
