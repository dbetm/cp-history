#include <bits/stdc++.h>

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
        if(a == b) return 1;
        if(i == (int)wordList.size()) return INT_MAX;
        if(dp[i] < INT_MAX) return dp[i];


        lli ans = INT_MAX;
        int n = wordList.size();
        for (int w = i; w <= n; ++w) {
            if(this->compareDeltaOne(a, wordList[i-1])) {
                watch(a)
                watch(wordList[i-1])
                lli subAns = 1 + this->genMinSeq(
                    wordList[i-1], b, wordList, i+1, dp
                );

                if(subAns < ans) {
                    ans = subAns;
                }
            }
        }

        return dp[i] = ans;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        lli dp[wordList.size() + 1];
        memset(dp, INT_MAX, sizeof (dp));
        dp[0] = 1;
        lli ans = this->genMinSeq(beginWord, endWord, wordList, 1, dp);

        if(ans >= INT_MAX) return 0;

        return (int)ans;
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
