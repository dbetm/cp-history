#include <bits/stdc++.h>
using namespace std;

bool esPalindromo(string str) {
    bool ans = true;
    int n = str.size();
    for (int i = 0, j = n-1; i < n/2; i++, j--) {
        if(str[i] != str[j]) {
            ans = false;
            break;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string str;
    cin >> n;
    while(n--) {
        cin >> str;
        if(esPalindromo(str)) cout << "P" << endl;
        else cout << "NP" << endl;
    }

    return 0;
}
