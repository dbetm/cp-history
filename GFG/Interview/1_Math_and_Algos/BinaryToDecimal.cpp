#include <bits/stdc++.h>

using namespace std;

typedef long int li;

li toDecimal(string);

int main() {
    int t;
    cin >> t;
    string binary;
    while(t--) {
        cin >> binary;
        cout << toDecimal(binary) << endl;
    }
    return 0;
}

li toDecimal(string binary) {
    int j = 0;
    li ans = 0;
    for (int i = binary.size()-1; i >= 0; i--, j++) {
        if(binary[i] == '1') ans += pow(2, j);
    }
    return ans;
}
