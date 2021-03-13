#include <bits/stdc++.h>
// https://leetcode.com/problems/single-number/
// Tag(s): Bit manipulation, implementation
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
    int singleNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();

        for (int i = 0; i < n; i++) ans = ans ^ nums[i];

        return ans;
    }
};

int main() {
    fastIO
    int n;
    cin >> n;
    vi nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.singleNumber(nums) << endl;
	return 0;
}
