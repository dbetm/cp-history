#include <bits/stdc++.h>
// https://leetcode.com/problems/zigzag-conversion/
// Tag(s): Implementation
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
    string convert(string s, int numRows) {
        bool getOff = true;
        int level = 0;
        int n = s.size();
        string *levels = new string[numRows];
        string ans = "";

        for (int i = 0; i < n; i++) {
            levels[level].push_back(s.at(i));
            if(level - 1 < 0) getOff = true;
            else if(level + 1 == numRows) getOff = false;
            //watch(level)
            if(getOff) level = (level + 1) % numRows;
            else level = (level - 1 + numRows) % numRows;
        }

        for (int i = 0; i < numRows; i++) {
            ans += levels[i];
        }

        return ans;
    }
};

int main() {
    fastIO
    string str;
    int numRows;
    Solution sol;

    cin >> str;
    cin >> numRows;
    cout << sol.convert(str, numRows) << endl;

	return 0;
}
