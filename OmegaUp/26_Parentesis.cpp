#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/COMI-Parentesis#problems
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool ans = true;
    string c;

    cin >> c;

    for (unsigned int i = 0, j = c.size()-1; i <= c.size() / 2; i++, j--) {
        if((c[i] == '(' && c[j] == ')') || (c[i] == ')' && c[j] == '(') && c.size() != 2)
            continue;
        ans = false;
        break;
    }

    if(ans) cout << "SI" << endl;
    else cout << "NO" << endl;
}
