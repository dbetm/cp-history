#include <bits/stdc++.h>
// https://www.interviewbit.com/problems/shortest-unique-prefix/
// Tag(s): Trie, strings
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

struct TrieNode {
    TrieNode *children[26];
    bool isEnd;
};

TrieNode *buildTrie(vector<string> &A) {
    int key;
    TrieNode *root = new TrieNode();

    for(string word : A) {
        TrieNode *tmp = root;

        int m = word.size();
        for (int i = 0; i < m; ++i) {
            key = int(word[i]) - 97;
            if(tmp->children[key] == NULL) {
                tmp->children[key] = new TrieNode();
                tmp->children[key]->isEnd = true;
            }
            else {
                tmp->children[key]->isEnd = false;
            }
            tmp = tmp->children[key];
        }
    }

    return root;
}

void printTraversal(TrieNode *node) {
    if(node == NULL) return;

    for (int i = 0; i < 26; ++i) {
        if(node->children[i] != NULL) {
            cout << char(i + 97) << " isEnd " << node->children[i]->isEnd << endl;
        }
        printTraversal(node->children[i]);
    }
}

string getShortestPrefix(TrieNode *root, string word) {
    string prefix = "";
    int n = word.size(), key;
    TrieNode *tmp = root;

    for (int i = 0; i < n; ++i) {
        key = int(word[i]) - 97;
        prefix += char(key + 97);

        if(tmp->children[key]->isEnd) break;

        tmp = tmp->children[key];
    }

    return prefix;
}

class Solution {
public:
    Solution();
    vector<string> prefix(vector<string> &A);
};

Solution::Solution() {}

vector<string> Solution::prefix(vector<string> &A) {
    TrieNode *root = buildTrie(A);

    vector<string> prefixes;

    for(string word : A) {
        prefixes.push_back(getShortestPrefix(root, word));
    }

    return prefixes;
}

int main() {
    int n;
    cin >> n;
    vector<string> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Solution sol;

    vector<string> ans = sol.prefix(A);

    for(string word : ans) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
