#include <bits/stdc++.h>
// https://omegaup.com/arena/CHOLO#problems/Nacho-el-flojo
using namespace std;

int main() {
    string ans = "";
    int t;
    cin >> t;
    int x, y, x1, y1, x2, y2;
    int a, a1, b, b1, c, c1, d, d1;
    for (int i = 0; i < t; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x = x1 + x2;
        y = y1 + y2;
        cin >> a >> a1;
        cin >> b >> b1;
        cin >> c >> c1;
        cin >> d >> d1;
        if(x == a && y == a1) ans += "A";
        else if(x == b && y == b1) ans += "B";
        else if(x == c && y == c1) ans += "C";
        else ans += "D";
    }
    cout << ans << endl;
    return 0;
}
