#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Program for calculate function prefix of given a string s

void prefix_function(vector<int> &pi, string s, int n);

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cou.tie(0;)
    int n;
    string s;
    cout << "Type string: ";
    cin >> s;
    n = s.size();
    vector<int> pi(n);
    prefix_function(pi, s, n);
    // Values for pi[i]
    for (int i = 0; i < n; i++) {
        cout << "p[" << i << "] = " << pi[i] << endl;
    }

    return 0;
}

void prefix_function(vector<int> &pi, string s, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            if(s.substr(0, k) == s.substr(i-k+1, k))
                pi[i] = k;
        }
    }
}
