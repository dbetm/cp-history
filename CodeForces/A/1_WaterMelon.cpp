#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int w;
    cin >> w;
    bool ans = false;
    for (int i = 1, j = w-1; i <= w/2; i++, j--) {
        if(!(i & 1) && !(j & 1)) {
            ans = true;
            break;
        }
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
