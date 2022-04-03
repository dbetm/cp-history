#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    int n = s.size();
    bool isPalindrome = true;

    for(int i = 0, j = n - 1; i < n / 2; ++i, --j) {
        if(s[i] == 'b' && s[j] == 'd') continue;
        else if(s[i] == 'd' && s[j] == 'b') continue;
        else if(s[i] == 'p' && s[j] == 'q') continue;
        else if(s[i] == 'q' && s[j] == 'p') continue;
        else if(s[i] == 'A' && s[j] == 'A') continue;
        else if(s[i] == 'H' && s[j] == 'H') continue;
        else if(s[i] == 'I' && s[j] == 'I') continue;
        else if(s[i] == 'i' && s[j] == 'i') continue;
        // else if(s[i] == 'l' && s[j] == 'l') continue; // check
        else if(s[i] == 'm' && s[j] == 'm') continue;
        else if(s[i] == 'M' && s[j] == 'M') continue;
        else if(s[i] == 'N' && s[j] == 'N') continue;
        else if(s[i] == 'o' && s[j] == 'o') continue;
        else if(s[i] == 'O' && s[j] == 'O') continue;
        // else if(s[i] == 't' && s[j] == 't') continue; // check
        else if(s[i] == 'T' && s[j] == 'T') continue;
        else if(s[i] == 'u' && s[j] == 'u') continue;
        else if(s[i] == 'U' && s[j] == 'U') continue;
        else if(s[i] == 'v' && s[j] == 'v') continue;
        else if(s[i] == 'V' && s[j] == 'V') continue;
        else if(s[i] == 'w' && s[j] == 'w') continue;
        else if(s[i] == 'W' && s[j] == 'W') continue;
        else if(s[i] == 'x' && s[j] == 'x') continue;
        else if(s[i] == 'X' && s[j] == 'X') continue;
        else if(s[i] == 'Y' && s[j] == 'Y') continue;
        else {
            isPalindrome = false;
            break;
        }
    }

    if(isPalindrome) cout << "TAK" << endl;
    else cout << "NIE" << endl;

    return 0;
}
