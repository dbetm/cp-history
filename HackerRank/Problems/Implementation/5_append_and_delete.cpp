#include <bits/stdc++.h>
// falla en algunos casos
using namespace std;

int main(int argc, char* argv[]) {
    string s, t;
    unsigned int k, cont = 0, aux, delta;
    unsigned int i;

    cin >> s;
    cin >> t;
    cin >> k;

    if(s.size() > t.size()) aux = s.size();
    else aux = t.size();

    for (i = 0; i < s.size() || i < t.size(); i++) {
        if(s[i] == t[i]) cont++;
        else break;
    }

    if(t.size() == s.size()) {
        if((t.size() - i) + (s.size() - i) == k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        delta = aux - cont;
        if(delta == k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
