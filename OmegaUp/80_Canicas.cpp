#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c, pos;
    cin >> n >> c;
    int a[n+1] = {0};
    while(c--) {
        cin >> pos;
        a[pos]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
