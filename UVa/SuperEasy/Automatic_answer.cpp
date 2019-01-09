#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        cout << (abs(n) / 10) % 10 << endl;
    }
    return 0;
}
