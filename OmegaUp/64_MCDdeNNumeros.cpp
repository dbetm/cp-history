#include <bits/stdc++.h>

using namespace std;

int mcd(int a, int b) {
    return b ? mcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, aux, ans = INT_MAX;
    cin >> n;
    cin >> a;
    for (int i = 1; i < n; i++) {
        cin >> b;
        aux = mcd(a, b);
        ans = min(aux, ans);
        a = b;
    }

    cout << ans << endl;
    return 0;
}
