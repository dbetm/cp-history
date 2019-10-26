#include <bits/stdc++.h>
// src: https://cp-algorithms.com
using namespace std;

int count_unique_substrings(string s) {
    int n = s.size();
    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    // Calcular las potencias de p
    for(int i = 0; i < n; i++) p_pow[i] = (p_pow[i-1] * p) % m;
    // Calcular los hashes de cada prefijo
    vector<long long> h(n+1, 0);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    int cnt = 0;
    long long cur_h;
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n-l; i++) {
            cur_h = (h[i+l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }

    return cnt;
}

int main() {
    string str;
    cout << "Type string: ";
    cin >> str;

    cout << "Unique substrings are: " << count_unique_substrings(str) << endl;
    // Example:
    /*
    input => "hola"
    output => 10
    why? =>
    hola {
        h, o, l, a;
        ho, ol, la;
        hol, ola;
        hola
    }
    */

    return 0;
}
