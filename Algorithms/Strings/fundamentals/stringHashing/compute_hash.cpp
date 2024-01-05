#include <bits/stdc++.h>
// src: https://cp-algorithms.com
using namespace std;

long long compute_hash(string str) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for(char c : str) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }

    return hash_value;
}

int main() {
    string str;
    cout << "Type string: ";
    cin >> str;
    cout << "function_hash(" << str << ") = " << compute_hash(str) << endl;
    return 0;
}
