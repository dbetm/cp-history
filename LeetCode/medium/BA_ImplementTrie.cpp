#include <bits/stdc++.h>
// https://leetcode.com/problems/implement-trie-prefix-tree/
// Tag(s); strings, trees, data structures
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    // TrieNode() {
    //     memset(children, NULL, sizeof(TrieNode*)*ALPHABET_SIZE);
    //     isEndOfWord = false;
    // }
};

class Trie {
private:
    TrieNode* root;

    void printTraversalInorder(TrieNode *node) {
        if(node == NULL) return;

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            printTraversalInorder(node->children[i]);
            if(node->children[i] != NULL) {
                cout << char(i + 97) << " isEndOfWord " << node->children[i]->isEndOfWord << endl;
            }
        }
    }

public:
    /** Initialize your data structure here. */
    Trie() {
        this->root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        int key;

        TrieNode *tmp = this->root;

        for (int i = 0; i < n; ++i) {
            key = int(word[i]) - 97;
            if(tmp->children[key] == NULL) {
                tmp->children[key] = new TrieNode();
                tmp = tmp->children[key];
            }
            else {
                tmp = tmp->children[key];
            }
        }

        tmp->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        bool ans = true;
        int n = word.size();
        int key;

        TrieNode *tmp = this->root;
        TrieNode *last = nullptr;

        for (int i = 0; i < n; ++i) {
            key = int(word[i]) - 97;
            if(tmp->children[key] == NULL) {
                ans = false;
                break;
            }
            else {
                last = tmp;
                tmp = tmp->children[key];
            }
        }

        if(ans and !last->children[key]->isEndOfWord) ans = false;

        return ans;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        bool ans = true;
        int n = prefix.size();
        int key;

        TrieNode *tmp = this->root;

        for (int i = 0; i < n; ++i) {
            key = int(prefix[i]) - 97;
            if(tmp->children[key] == NULL) {
                ans = false;
                break;
            }
            else tmp = tmp->children[key];
        }

        return ans;
    }

    void print() {
        TrieNode *tmp = this->root;
        this->printTraversalInorder(tmp);
    }
};

int main() {
    int n, s, pre;
    cin >> n;
    string word, prefix;
    Trie trie;

    for (int i = 0; i < n; ++i) {
        cin >> word;
        trie.insert(word);
    }

    cin >> s;
    for (int i = 0; i < s; ++i) {
        cin >> word;
        cout << trie.search(word) << endl;
    }

    cin >> pre;
    for (int i = 0; i < pre; ++i) {
        cin >> prefix;
        cout << trie.startsWith(prefix) << endl;
    }
    //trie.print();

    return 0;
}
