#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/palindrome-string/0/
// tag(s): strings
using namespace std;

bool isPalindrome(string str);

int main() {
    int t, tam;
    string str;
    cin >> t;

    while(t--) {
        cin >> tam;
        cin >> str;
        cout << (isPalindrome(str) ? "Yes" : "No") << endl;
    }
    return 0;
}

bool isPalindrome(string str) {
    int len = str.size();
    int j = len-1;
    bool ans = true;
    for (size_t i = 0; i < len; i++, j--) {
        if(str[i] != str[j]) {
            ans = false;
            break;
        }
    }
    return ans;
}