#include <bits/stdc++.h>
// https://leetcode.com/problems/minimum-genetic-mutation/
// Tag(s): BFS, strings
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

class Solution {
public:
    // BFS
    int minMutation(string start, string end, vector<string>& bank) {
        if(find(bank.begin(), bank.end(), end) == bank.end()) return -1;

        queue<string> q;
        q.push(start);
        int ans = 0;
        unordered_set<string> bankSet(bank.begin(), bank.end());
        vector<char> bases{'A', 'C', 'G', 'T'};

        while(!q.empty()) {
            int n = q.size();
            // iterar sobre el nivel actual
            for (int i = 0; i < n; ++i) {
                string gen = q.front();
                q.pop();

                if(gen == end) return ans;

                bankSet.erase(gen);

                // add all the genes that differ in only one base
                for (int j = 0; j < 8; ++j) {
                    char aux = gen[j];
                    for(const char &base : bases) {
                        gen[j] = base;
                        if(bankSet.find(gen) != bankSet.end()) q.push(gen);
                    }
                    gen[j] = aux;
                }
            }
            ++ans;
        }

        return -1;
    }
};

int main() {
    fastIO
    string start, end;
    int numValids;

    cin >> start >> end;
    cin >> numValids;

    vector<string> bank(numValids);
    for (int i = 0; i < numValids; i++) {
        cin >> bank[i];
    }

    Solution s;

    cout << s.minMutation(start, end, bank) << endl;

	return 0;
}
