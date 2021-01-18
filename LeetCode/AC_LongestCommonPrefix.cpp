#include <bits/stdc++.h>
// https://leetcode.com/problems/longest-common-prefix/
// Tag(s): Implementation, strings
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
        string longestCommonPrefix(vector<string>& strs) {
            string ans = "";

            if(strs.empty()) return ans;
            // assume that first string is the smallest lenght
            string base = strs[0];
            int m = base.size(), n = strs.size();

            for (int i = 0; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if(i >= (int)strs[j].size() || base[i] != strs[j][i]) {
                        return ans;
                    }
                }

                ans += base[i];
            }

            return ans;
        }
};

int main() {
    fastIO
    int n;
    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;

	return 0;
}
