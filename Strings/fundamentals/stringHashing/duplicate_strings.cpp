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

vector<vector<int>> group_identical_strings(vector<string> s) {
    int n = s.size();
    vector<pair<long, long>> hashes(n);

    for (int i = 0; i < n; i++) hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());
    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if(i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back(); // vector vacío
        groups.back().push_back(hashes[i].second); // insertar el índice
    }
    return groups;
}

int main() {
    int n;
    string word;
    cout << "Type number of words: ";
    cin >> n;
    vector<string> words;

    while(n--) {
        cin >> word;
        words.push_back(word);
    }

    vector<vector<int>> groups = group_identical_strings(words);
    cout << "Groups: " << endl;

    vector<vector<int>>::iterator it;

    for (it = groups.begin(); it != groups.end(); ++it) {
        vector<int> aux = *it;
        n = aux.size();
        for (int j = 0; j < n; j++) {
            cout << aux[j] << " ";
        }
        cout << endl;
    }


    return 0;
}
