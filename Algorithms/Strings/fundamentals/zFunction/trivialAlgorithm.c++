#include <bits/stdc++.h>

using namespace std;

vector<int> z_function_trivial(string str);

int main() {
    string str;
    cout << "Type string: ";
    cin >> str;
    vector<int> z = z_function_trivial(str);
    cout << "The Z-Function for " << str << " is:" << endl;
    int n = (int)z.size();
    for (int i = 0; i < n; i++) {
        cout << z[i] << " ";
    }
    cout << endl;
    return 0;
}

vector<int> z_function_trivial(string s) {
    int n = (int)s.size();
    vector<int> z(n);

    for (int i = 1; i < n; i++) {
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    }

    return z;
}
