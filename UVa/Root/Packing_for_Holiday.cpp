#include <bits/stdc++.h>

using namespace std;

int main() {
    short t, L, W, H;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> L;
        cin >> W;
        cin >> H;
        if(W > L || H > L) cout << "Case " << i+1 << ": " << "bad" << "\n";
        else cout << "Case " << i+1 << ": " << "good" << "\n";
    }
    return 0;
}
