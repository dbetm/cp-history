#include <bits/stdc++.h>

using namespace std;

string esPalindromo(string p) {
    string ans = "P";
    int len = p.size();
    int lim = (len%2 == 0)? len/2 : len/2 -1;
    for (int i = 0; i < lim; i++) {
        if(p[i] != p[len-1-i]) {
            ans = "NP";
            break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string palabra;
    for (int i = 0; i < n; i++) {
        cin >> palabra;
        cout << esPalindromo(palabra) << endl;
    }
    return 0;
}
