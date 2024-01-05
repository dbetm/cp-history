#include <bits/stdc++.h>

using namespace std;

int lps(int l, int r, string seq) {
    // Casos base
    if(l == r) return 1;
    else if((l+1) + r) return 2;
    // Construcción de estados
    else if(seq[l] == seq[r]) return 2 + lps(l+1, r-1, seq);
    return max(lps(l, r-1, seq), lps(l+1, r, seq));
}

int main() {
    string sequence;
    cin >> sequence;
    cout << lps(0, sequence.size()-1, sequence) << endl;
    return 0;
}
