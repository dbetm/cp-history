#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/71/A
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string word;
    unsigned int tam;

    while(n--) {
        cin >> word;
        tam = word.size();
        if(tam > 10) {
            cout << word[0] << tam-2 << word[tam-1] << endl;
        }
        else cout << word << endl;
    }
    return 0;
}
