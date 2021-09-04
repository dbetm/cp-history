#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

class Trie {
private:
    TrieNode* root;
    void printTrie() {

    }
public:
    /** Initialize your data structure here. */
    Trie() {
        this->root = new TrieNode;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        int key;

        TrieNode *tmp = this->root;

        for (int i = 0; i < n; ++i) {
            key = int(word[i]) - 97;
            if(tmp->children[key] == NULL) {

            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return false;
    }
};

int main() {

    return 0;
}
