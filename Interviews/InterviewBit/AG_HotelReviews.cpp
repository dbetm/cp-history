#include <bits/stdc++.h>
// https://www.interviewbit.com/problems/hotel-reviews/
// Tag(s): estructuras de datos, cadenas, trie
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

struct TrieNode {
    TrieNode *children[26];
    bool isEnd;
};

TrieNode *buildTrie(string A) {
    int idx = 0, key;
    int n = A.size();
    TrieNode *root = new TrieNode();

    while(idx < n) {
        TrieNode *tmp = root;
        string word = "";
        while(idx < n and A[idx] != '_') {
            word += A[idx];
            ++idx;
        }
        ++idx;

        int m = word.size();
        for (int i = 0; i < m; ++i) {
            key = int(word[i]) - 97;
            if(tmp->children[key] == NULL) {
                tmp->children[key] = new TrieNode();
            }
            tmp = tmp->children[key];
        }
        tmp->isEnd = true;
    }

    return root;
}

bool compareFN(pair<int, int> &a, pair<int, int> &b) {
    if(a.first == b.first) return a.second > b.second;

    return a.first < b.first;
}

bool searchWord(TrieNode *root, string word) {
    bool ans = true;
    int n = word.size(), key;
    TrieNode *tmp = root;

    for (int i = 0; i < n; ++i) {
        key = int(word[i]) - 97;

        if(tmp->children[key] == NULL) {
            ans = false;
            break;
        }
        tmp = tmp->children[key];
    }

    if(ans and !tmp->isEnd) ans = false;

    return ans;
}

class Solution {
public:
    Solution();
    vector<int> solve(string A, vector<string> &B);
};

Solution::Solution() {}

vector<int> Solution::solve(string A, vector<string> &B) {
    TrieNode *root = buildTrie(A);
    vector<int> ANS;
    vector<pair<int, int>> tmp;
    int numReviews = B.size();

    for (int i = 0; i < numReviews; ++i) {
        string review = B[i];
        int numGoodWords = 0;
        int m = review.size();
        int j = 0;
        while(j < m) {
            string word = "";
            while(j < m and review[j] != '_') {
                word += review[j];
                ++j;
            }
            ++j;
            if(searchWord(root, word)) {
                ++numGoodWords;
            }
        }
        tmp.push_back({numGoodWords, i});
    }

    sort(tmp.rbegin(), tmp.rend(), compareFN);

    int x = tmp.size();

    for (int i = 0; i < x; ++i) {
        ANS.push_back(tmp[i].second);
    }

    return ANS;
}

int main() {
    fastIO
    string A;
    cin >> A;

    int n;
    cin >> n;
    vector<string> B(n);

    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    Solution sol;

    vector<int> ans = sol.solve(A, B);

    for(auto index : ans) {
        cout << index << " ";
    }
    cout << endl;

	return 0;
}
