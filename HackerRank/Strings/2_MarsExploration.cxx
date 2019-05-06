#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/mars-exploration/problem
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int cont = 0;

    for (unsigned int i = 0; i < s.size()-2; i += 3) {
        if(s[i] != 'S') cont++;
        if(s[i+1] != 'O') cont++;
        if(s[i+2] != 'S') cont++;
    }

    cout << cont << endl;

    return 0;
}
