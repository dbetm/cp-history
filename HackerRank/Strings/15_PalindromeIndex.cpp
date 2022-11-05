#include <bits/stdc++.h>

using namespace std;


int getPalindromeIndex(string s) {
    int n = s.size();
    int r_differences = 0, l_differences = 0;
    int i = 0, j = n-1;
    int r_index = -1, l_index = 0;

    // left differences
    while(i < (n/2) and j > (n/2)) {
        if(s[i] != s[j]) {
            l_differences++;
            l_index = i;
        }
        else {
            --j;
        }
        ++i;
    }

    if(l_differences == 1) {
        return l_index;
    }

    // reset pointers
    i = 0;
    j = n-1;

    // right differences
    while(i < (n/2) and j > (n/2)) {
        if(s[i] != s[j]) {
            r_differences++;
            r_index = j;
        }
        else {
            ++i;
        }
        --j;
    }

    if(r_differences == 1) {
        return r_index;
    }

    return -1;
}


int main() {
    int num_queries;
    cin >> num_queries;

    for(int i = 0; i < num_queries; ++i) {
        string s;
        cin >> s;

        cout << getPalindromeIndex(s) << endl;
    }

    return 0;
}
