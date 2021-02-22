#include <bits/stdc++.h>

using namespace std;

void printAllPermutations(string str, int i=0) {
    if(str[i] == '\0') {
        cout << str << endl; // ABC
        return;
    }

    for (size_t j = i; j < str.size(); j++) {
        swap(str[i], str[j]);
        printAllPermutations(str, i+1);
        // swap(str[i], str[j]);
    }
}

int main() {
    string str;
    cin >> str;
    printAllPermutations(str);
    return 0;
}
