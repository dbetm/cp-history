#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Al-reves-20#problems
using namespace std;

int main() {
    int i, f;
    string texto, substring;
    cin >> i >> f;
    cin.get();
    getline(cin, texto);
    substring = texto.substr(i, f-i+1);
    int k = substring.size();
    for (int j = 0; j < (int)texto.size(); j++) {
        if(j >= i && j <= f) cout << substring[--k];
        else cout << texto[j];
    }
    cout << endl;
    return 0;
}
