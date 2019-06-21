#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> alturas(n);

    for (int64_t i = 0; i < n; i++) {
        cin >> alturas[i];
    }

    sort(alturas.begin(), alturas.end());

    for (int64_t i = 0; i < n; i++) {
        if((i+1) % k == 0) cout << alturas[i] << endl;
        else cout << alturas[i] << " ";
    }

    cout << endl;

    return 0;
}
