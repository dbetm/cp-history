#include <bits/stdc++.h>

using namespace std;

int main() {
    int nw;
    string word;
    cin >> nw;

    for (int i = 0; i < nw; ++i) {
        cin >> word;
        if(word.length() == 3) {
            if((word[0] == 'o' && word[1] != 'w') || (word[1] == 'n' && word[0] != 't') || (word[2] == 'e' && word[0] != 't'))
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        else {
            cout << 3 << endl;
        }
    }

    return 0;
}
