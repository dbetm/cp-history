#include <bits/stdc++.h>
// https://leetcode.com/problems/excel-sheet-column-number
// Tag(s): Implementation, math
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
    int titleToNumber(string s) {
        int ans = 0, n = s.size();
        lli power = 1;

        for (int i = n-1; i >= 0; i--) {
            ans += (s[i]-64) * power;
            power *= 26;
        }

        return ans;
    }
};

int main() {
    fastIO
    string title;
    cin >> title;

    Solution sol;
    cout << sol.titleToNumber(title) << endl;

	return 0;
}
