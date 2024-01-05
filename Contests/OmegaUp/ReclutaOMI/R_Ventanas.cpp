#include <bits/stdc++.h>
// Parcialmente correcta
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cont = 1;
    int r1, s1, r2, s2;
    cin >> n;
    pair<int, int> c;
    cin >> c.first >> s1 >> r2 >> c.second;
    n--;

    while(n--) {
        cin >> r1 >> s1 >> r2 >> s2;
        if((c.first >= r1 && c.first <= r2) &&  (c.second >= s1 && c.second <= s2))
            cont++;
    }

    cout << cont << endl;
    return 0;
}
