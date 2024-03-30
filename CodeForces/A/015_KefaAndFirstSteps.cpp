#include <bits/stdc++.h>
// https://codeforces.com/contest/580/problem/A
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ant, actual, aux = 0, ans = 0;
    cin >> n;
    cin >> ant;
    aux++;
    n--;
    if(n == 0) cout << 1 << endl;
    else {
        do {
            cin >> actual;
            if(actual >= ant) {
                //cout << ant << "-" << actual << endl;
                aux++;
            }
            else {
                ans = max(ans, aux);
                aux = 1;
            }
            ant = actual;
        } while(--n);
        ans = max(ans, aux);
        cout << ans << endl;
    }
    return 0;
}
