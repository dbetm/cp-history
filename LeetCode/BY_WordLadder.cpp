#include <bits/stdc++.h>
// https://leetcode.com/problems/word-ladder/
// Tag(s): BFS, Graphs, Strings
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

typedef long long int lli;

class Solution {
    bool compareDeltaOne(string a, string b) {
        bool ans = true;
        int deltas = 0;

        int n = a.size();

        for (int i = 0; i < n; i++) {
            if(a[i] != b[i]) deltas++;
            if(deltas > 1) {
                ans = false;
                break;
            }
        }

        return ans;
    }

    lli genMinSeq(string a, string b, vector<string> &wordList, int i, lli dp[]) {
        if(a == b) return dp[i] = 1;
        if(i >= (int)wordList.size()) return INT_MAX;
        if(dp[i] != -1) return dp[i];


        lli ans = INT_MAX;
        int n = wordList.size();
        for (int w = 0; w < n; ++w) {
            if(i == w) continue;
            if(this->compareDeltaOne(a, wordList[w])) {
                //watch(a)
                //watch(wordList[i-1])
                lli including = 1 + this->genMinSeq(
                    wordList[w], b, wordList, i+1, dp
                );
                lli excluding = this->genMinSeq(
                    a, b, wordList, i+1, dp
                );

                if(including < excluding) {
                    ans = including;
                }
                else  ans = excluding;
            }
        }

        return dp[i] = ans;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        queue<string> q;
        int ans = 1;
        q.push(beginWord);
        unordered_set<string> dict(wordList.begin(), wordList.end());

        while(!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();

                if(word == endWord) {
                    return ans;
                }

                dict.erase(word);

                int m = word.size();
                for (int j = 0; j < m; j++) {
                    char c = word[j];
                    for (int l = 0; l < 26; l++) {
                        word[j] = 'a' + l;
                        if(dict.find(word) != dict.end()) {
                            q.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
            ans++;
        }

        return 0;
    }
};

int main() {
    string beginWord, endWord;
    cin >> beginWord;
    cin >> endWord;

    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++) cin >> wordList[i];

    Solution sol;
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
