#include <bits/stdc++.h>

using namespace std;

/* Input:
n : 32-bits positive integer
*/
string decimalToBinary(int n) {
    assert(n > 0);
    string ans = "";

    while(n) {
        if(n & 1) ans += '1';
        else ans += '0';

        n >>= 1;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << decimalToBinary(n) << endl;

    return 0;
}
