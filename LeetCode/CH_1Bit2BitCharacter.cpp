#include <bits/stdc++.h>
// https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Tag(s): Arrays, implementation
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
    int n = bits.size();
    if(n == 1) return bits[0] == 0;

    if(bits[n-1] == 1 or (n == 2 and bits[0] == 1)) return false;

    bool twoBits = bits[0] == 1;

    for (int i = 1; i < n-1; ++i) {
        if(twoBits) {
            twoBits = false;
        }
        else if(bits[i] == 1) {
            twoBits = true;
        }
    }

    return bits[n-1] == 0 and twoBits == false;
}
/*
Alternative: The numbers of 1 between the last 0 and the second last
0 determine the answer.

bool isOneBitCharacter(vector<int>& bits) {
    int count_1 = 0;
    for (int i = (int) bits.size() - 2; i >= 0 && bits[i] == 1; i--) count_1++;
    return (count_1 % 2 == 0);
}
*/

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
