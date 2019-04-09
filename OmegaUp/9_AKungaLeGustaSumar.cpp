#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/A-kunga-le-gusta-sumar#problems
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    int64_t res;

    while (cin >> n) {
        if(n == 0) break;
        res = (n* (n+1)) / 2;
        cout << res << endl;
    }

    return 0;
}
