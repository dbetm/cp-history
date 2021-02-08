#include <bits/stdc++.h>
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Tag(s): data structures, strings
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack< pair<char, int> > auxStack;
        int n = str.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            if(auxStack.empty() || str[i] != auxStack.top().first) {
                auxStack.push(make_pair(str[i], 1));
            }
            else {
                auxStack.top().second++;
                if(auxStack.top().second == k) {
                    auxStack.pop();
                }
            }
        }

        while(!auxStack.empty()) {
            int count = auxStack.top().second;
            while(count--) {
                ans.push_back(auxStack.top().first);
            }
            auxStack.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    fastIO
    string str;
    int k;
    Solution sol;

    cin >> str >> k;

    cout << sol.removeDuplicates(str, k) << endl;

	return 0;
}
