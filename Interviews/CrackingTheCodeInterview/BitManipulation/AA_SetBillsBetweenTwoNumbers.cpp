#include <bits/stdc++.h>
/* You are given two 32-bit numbers, N and M, and two bit positions, i and j.
Write a method to set all bits between i and j in N equal to M  (e.g., M
becomes a substring of N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100
*/
using namespace std;

#define glow(x) cout << (#x) << "=" << x << " -> " << decimalToBinary(x) << endl;

string decimalToBinary(int n);

int combine(int n, int m, int i, int j) {
    int max = ~0; // all ones

    // put all 1's from front to j position
    int left = max - ((1 << j) - 1);
    // put all 1's after i positiom
    int right = (1 << i) - 1;

    // create a mask: it has all 1's except to the range (j-1, i)
    int mask = left | right;

    int ans = (n & mask) | (m << i);

    return ans;
}

int main() {
    int n, m, i, j;
    cin >> n >> m;
    cin >> i >> j;

    glow(n)
    glow(m)
    int ans = combine(n, m, i, j);
    glow(ans)

    return 0;
}

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
