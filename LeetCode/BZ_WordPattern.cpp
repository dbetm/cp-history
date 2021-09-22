#include <bits/stdc++.h>
// https://leetcode.com/problems/word-pattern/
// Tag(s): strings, implementation, estructuras de datos
using namespace std;

#define watch(x) cout << (#x) << " is "<< x << endl;

bool wordPattern(string pattern, string s) {
    bool ans = true;
    unordered_map<char, string> dic;

    int n = pattern.size();
    int indexWords = 0;
    int numWords = 0;
    int m = s.size();

    set<char> uniqueChars;
    set<string> uniqueWords;

    for (int i = 0; i < n; ++i) {
        string word = "";
        while(indexWords < m and s[indexWords] != ' ') {
            word += s[indexWords];
            indexWords++;
        }
        uniqueWords.insert(word);
        // check in the dictionary
        if(dic.find(pattern[i]) == dic.end()) {
            dic[pattern[i]] = word;
            uniqueChars.insert(pattern[i]);
        }
        else {
            if(dic[pattern[i]] != word) {
                ans = false;
                break;
            }
        }

        indexWords++;
        numWords++;
        if(indexWords >= m) break;
    }

    if(numWords < n or uniqueChars.size() != uniqueWords.size()) ans = false;
    else if(indexWords < m) ans = false;

    return ans;
}

int main() {
    string pattern, s;
    cin >> pattern;
    cin.get();
    getline(cin, s);

    cout << wordPattern(pattern, s) << endl;

    return 0;
}
