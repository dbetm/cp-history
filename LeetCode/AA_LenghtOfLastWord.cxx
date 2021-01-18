#include <bits/stdc++.h>
// https://leetcode.com/problems/length-of-last-word/
// Tag(s): Implementación, cadenas
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
        int lengthOfLastWord(string s) {
            int n = s.size();
            int cont = 0, i = n-1;

            while(i >= 0 && s[i] == ' ') {
                i--;
            }

            while (i >= 0 && s[i] != ' ') {
                cont++;
                i--;
            }

            return cont;
        }
};

int main() {
    fastIO
    string s;
    Solution sol;

    getline(cin, s);

    cout << sol.lengthOfLastWord(s) << endl;

	return 0;
}
