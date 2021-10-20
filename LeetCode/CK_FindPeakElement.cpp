#include <bits/stdc++.h>
// https://leetcode.com/problems/find-peak-element/
// Tag(s): Binary Search, arrays
using namespace std;

void explore(vector<int> &nums, int left, int right, int &ans) {
    if(left >= right) return;

    if(nums[right] > nums[left] and nums[ans] < nums[right]) {
        ans = right;
    }
    else if(nums[ans] < nums[left]) {
        ans = left;
    }

    int middle = (right - left) / 2 + left;
    explore(nums, left, middle, ans);
    explore(nums, middle + 1, right, ans);
}

int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if(n == 1 or nums[0] > nums[1]) return 0;
    else if(nums[n-1] > nums[n-2]) return n-1;
    int ans = 0;

    explore(nums, 0, n-1, ans);

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << findPeakElement(nums) << endl;

    return 0;
}
