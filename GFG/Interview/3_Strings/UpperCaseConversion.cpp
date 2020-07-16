#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/upper-case-conversion/0/
// tag(s): strings
using namespace std;

void uppercase(string str) {
    int len = str.size();
    string aux = "";
    for (size_t i = 0; i < len; i++) {
        if(int(str[i]) == 32) {
            aux[0] = toupper(aux[0]);
            cout << aux << " ";
            aux = "";
        }
        else {
            aux += str[i];
        }
    }
    if(str.size() > 1) {
        aux[0] = toupper(aux[0]);
    }
    cout << aux << endl;
}

int main() {
    ios_base::sync_with_stdio(NULL); cin.tie(NULL);
    
    string str;
    int t;
    cin >> t;
    cin.get();
    while(t--) {
        getline(cin, str);
        uppercase(str);
    }
    
    return 0;
}
