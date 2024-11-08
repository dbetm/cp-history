#include <bits/stdc++.h>
// https://leetcode.com/problems/fizz-buzz/
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
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for (int i = 1; i <= n; i++) {
            if(i % 3 == 0 and i % 5 == 0) ans.push_back("FizzBuzz");
            else if(i % 3 == 0) ans.push_back("Fizz");
            else if(i % 5 == 0) ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }

        return ans;
    }
};

int main() {
    fastIO
    int n;
    Solution sol;
    cin >> n;

    vector<string> ans = sol.fizzBuzz(n);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

	return 0;
}
