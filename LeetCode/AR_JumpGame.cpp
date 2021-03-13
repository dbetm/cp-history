#include <bits/stdc++.h>
// https://leetcode.com/problems/jump-game/
// Tag(s): Implementation, greedy
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
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastGoodIndex = n-1;

        for (int i = n-2; i >= 0; i--) {
            if(i + nums[i] >= lastGoodIndex) {
                lastGoodIndex = i;
            }
        }

        return lastGoodIndex == 0;
    }
};

int main() {
    fastIO
    int n;
    Solution sol;

    cin >> n;
    vi nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << sol.canJump(nums) << endl;

	return 0;
}
