#include <bits/stdc++.h>
// https://codeforces.com/contest/580/problem/B
// Tag(s): Ventana, implementación
using namespace std;
#define watch(x) cout << (#x) << " es " << x << endl;
typedef long long int lli;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d, m, s;
    cin >> n >> d;

    vector<pair<int, int>> friends(n);

    for (int i = 0; i < n; i++) {
        cin >> m >> s;
        friends[i] = {m, s};
    }

    sort(friends.rbegin(), friends.rend());

    /*
    Usar 2 pivotes, a y b
    */
    lli hypothesis = 0, acumulado = 0;

    for (int a = 0, b = 0; a < n or b < n; a++) {

        while(1) {
            if(b < n && abs(friends[a].first - friends[b].first) < d) {
                acumulado += friends[b].second;
                b++;
            }
            else break;
        }

        if(a == b) {
            b++;
        }

        if(acumulado > hypothesis) hypothesis = acumulado;

        acumulado -= friends[a].second;
    }

    cout << hypothesis << endl;

    return 0;
}
