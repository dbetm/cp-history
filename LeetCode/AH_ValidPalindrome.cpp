#include <bits/stdc++.h>
// https://leetcode.com/problems/valid-palindrome/
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
    bool isPalindrome(string str) {
        int left = 0, right = str.size() - 1;

        while(left <= right) {
            while(left < right && !isalnum(str[left])) left++;
            while(left < right && !isalnum(str[right])) right--;

            if(toupper(str[left]) != toupper(str[right])) return false;

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    fastIO
    string str;
    Solution solution;

    getline(cin, str);

    cout << solution.isPalindrome(str) << endl;

	return 0;
}
