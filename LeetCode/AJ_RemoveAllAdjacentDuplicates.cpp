#include <bits/stdc++.h>
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Tag(s): Estructuras de datos, cadenas
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
    string removeDuplicates(string str) {
        int stptr = -1;
        int len = str.size();

        for (int i = 0; i < len; i++) {
            if(stptr == -1 || str[stptr] != str[i]) {
                stptr++;
                str[stptr] = str[i];
            }
            else {
                stptr--;
            }
        }

        return str.substr(0, stptr+1);
    }
};

int main() {
    fastIO
    Solution sol;
    string str;
    cin >> str;

    cout << sol.removeDuplicates(str) << endl;

	return 0;
}
