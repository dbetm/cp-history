#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string total, aux;
    cin >> total;
    cin >> aux;
    total += aux;
    cin >> aux;
    total += aux;

    sort(total.begin(), total.end());

    cout << total[total.size()/2] << endl;

    return 0;
}
