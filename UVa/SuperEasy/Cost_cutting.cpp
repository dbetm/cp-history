#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    int a, b, c;
    cin >> T;
    for (int i = 0; i < T; ++i){
        cin >> a >> b >> c;
        if((b > a && b < c) || (b > c && b < a))
            cout << "Case " << i+1 << ": " << b << endl;
        else if((a > b && a < c) || (a > c && a < b))
            cout << "Case " << i+1 << ": " << a << endl;
        else cout << "Case " << i+1 << ": " << c << endl;
    }

    return 0;
}
