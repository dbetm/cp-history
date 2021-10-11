#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
    int n = bits.size();
    if(n == 1) return bits[0] == 0;

    if(bits[n-1] == 1 or (n == 2 and bits[0] == 1)) return false;

    return bits[n-2] == 0 or (bits[n-1] and bits[n-2]) or (bits[n-1] == 0 and bits[n-2]);
}

int main() {
    int n;
    cin >> n;

    vector<int> bits(n);

    for(int i = 0; i < n; ++i) {
        cin >> bits[i];
    }

    cout << isOneBitCharacter(bits) << endl;

    return 0;
}
