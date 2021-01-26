#include <bits/stdc++.h>
// https://leetcode.com/problems/valid-palindrome-ii/
// Tag(s): strings
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
    bool isPalindrome(string str, int left, int right) {
        bool ans = true;

        while(left <= right) {
            if(str[left++] != str[right--]) {
                ans = false;
                break;
            }
        }

        return ans;
    }

    bool validPalindrome(string str) {
        bool ans = true;
        int left = 0, right = str.size() - 1;

        while(left <= right) {
            if(str[left] != str[right]) {
                if(isPalindrome(str, left, right-1) or isPalindrome(str, left+1, right)) {
                    break;
                }
                else {
                    ans = false;
                    break;
                }
            }
            left++;
            right--;
        }

        return ans;
    }
};

int main() {
    fastIO

    Solution solution;
    string str;
    cin >> str;

    cout << solution.validPalindrome(str) << endl;


	return 0;
}
