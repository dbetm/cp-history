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

int findPeakElement2(vector<int>& nums) {
    int n = nums.size();

    if(n == 1 or nums[0] > nums[1]) return 0;
    else if(nums[n-1] > nums[n-2]) return n-1;
    int ans = 0;

    explore(nums, 0, n-1, ans);

    return ans;
}

/* Best solution:
Fact, in the numbs array we have always falling and rising slopes, so
we can use binary search to seek for the peak, so if we have on the middle mid
1. nums[mid] > nums[mid + 1]
    Then we have a falling slope and we need to search in [left, mid]
2. nums[mid] < nums[mid + 1]
    We have a rising slope and we need to search in (mid, right]
*/
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while(left < right) {
        int middle = ((right - left) / 2) + left;

        if(nums[middle] > nums[middle + 1]) {
            right = middle;
        }
        else {
            left = middle + 1;
        }
    }

    return left;
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
