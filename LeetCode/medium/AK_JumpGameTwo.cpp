#include <bits/stdc++.h>
// https://leetcode.com/problems/jump-game-ii/
// Tag(s): greedy, implementation
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
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;
        int jumps = 1;
        int currentLadder = nums[0], biggestLadder = nums[0];

        for (int i = 1; i < n; i++) {
            if((currentLadder+i-1) >= (n-1) or i == (n-1)) return jumps;

            biggestLadder = max(biggestLadder, nums[i] + i);

            currentLadder--;

            // end current ladder so we need jump the next biggest ladder
            if(currentLadder == 0) {
                jumps++;
                currentLadder = biggestLadder - i; // 'cause overlap
            }
        }

        return jumps;
    }
};

int main() {
    fastIO
    int n;
    Solution sol;

    cin >> n;
    vi nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << sol.jump(nums) << endl;

	return 0;
}
