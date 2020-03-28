#include <bits/stdc++.h>
// Aceptado
using namespace std;
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

int main() {
    fastIO
    int n, a, b, cont = 0;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());

    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        if(data[i] >= a && data[i] <= b) {
            cont++;
        }
        if(data[i] >= b) break;
    }

    cout << cont << endl;

    return 0;
}
