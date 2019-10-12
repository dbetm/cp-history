#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    double res, r, a, b, n;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cin >> n;
        r = (b / a);
        res = a * pow(r, n-1);
        cout << floor(res) << endl;
    }
    return 0;
}
