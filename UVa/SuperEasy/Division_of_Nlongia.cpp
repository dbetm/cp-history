#include <bits/stdc++.h>
// URL: https://uva.onlinejudge.org/external/114/11498.pdf
using namespace std;

int main() {
    int k, n, m, x, y;

    while(cin >> k) {
        if(k == 0) break;
        cin >> n >> m;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            if(x == n || y == m) cout << "divisa" << "\n";
            else if(x > n && y > m) cout << "NE" << "\n";
            else if(x < n && y > m) cout << "NO" << "\n";
            else if(x < n && y < m) cout << "SO" << "\n";
            else cout << "SE" << "\n";
        }
    }
    return 0;
}
