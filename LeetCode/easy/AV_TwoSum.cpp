#include <bits/stdc++.h>
// https://leetcode.com/problems/two-sum/
// Tag(s): arrays, math
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

vector<int> twoSum(vector<int>& nums, int target) {
    // NOTE: It's possible to solve it on O(n) time, using an unordered map
    int n = nums.size();
    int left = 0, right = n - 1, idx1, idx2;

    vector<pair<int, int>> sortedNums;
    for (int i = 0; i < n; i++) {
        sortedNums.push_back({nums[i], i});
    }

    sort(sortedNums.begin(), sortedNums.end());

    while(left < right) {
        if(sortedNums[left].first + sortedNums[right].first == target) {
            idx1 = sortedNums[left].second;
            idx2 = sortedNums[right].second;
            break;
        }
        else if(sortedNums[left].first + sortedNums[right].first > target) --right;
        else ++left;
    }

    vector<int> ans;
    ans.push_back(idx1);
    ans.push_back(idx2);
    return ans;
}

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> target;

    auto ans = twoSum(nums, target);
    for(const auto & index : ans) {
        cout << index << " -> " << nums[index] << endl;
    }

    return 0;
}
