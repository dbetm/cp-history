#include <bits/stdc++.h>

using namespace std;
typedef long int li;

li getHandshakes(li);

int main(int argc, char const *argv[]) {
    li t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << getHandshakes(n) << "\n";
    }

    return 0;
}

li getHandshakes(li n) {
    li ans;
    ans = (n * (n - 1)) / 2;
    return ans;
}
