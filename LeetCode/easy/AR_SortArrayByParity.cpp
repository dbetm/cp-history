#include <bits/stdc++.h>
// https://leetcode.com/problems/sort-array-by-parity/
// Tag(s): arrays, implementation
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return nums;

        int a = 0, b = 1;

        while(b < n) {
            if(!(nums[b] & 1) and nums[a] & 1) {
                swap(nums[a], nums[b]);
            }
            if(!(nums[a] & 1)) a++;

            b++;
        }

        return nums;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    Solution sol;
    vector<int> ans = sol.sortArrayByParity(nums);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
