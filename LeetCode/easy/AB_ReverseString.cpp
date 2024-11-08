#include <bits/stdc++.h>
// https://leetcode.com/problems/reverse-string/
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
        void reverseString(vector<char> &s) {
            int left = 0, right = s.size()-1;
            while(left < right) {
                swap(s[left++], s[right--]);
            }
        }
};

int main() {
    fastIO
    string aux;
    cin >> aux;

    vector<char> s(aux.begin(), aux.end());
    Solution sol;
    sol.reverseString(s);

    for(const char &c: s)
        cout << c;
    cout << endl;

	return 0;
}
