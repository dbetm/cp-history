#include <bits/stdc++.h>
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Tag(s): Binary search, arreglos, implementación, sorting
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, middle;
        int ansIndex = -1;

        while(start <= end) {
            middle = (start + end) / 2;
            // watch(middle)
            // case 1: We found the answer
            if(nums[middle] == target) {
                ansIndex = middle;
                break;
            }
            // case 2: We'll find in first segment (left-right way)
            else if(nums[middle] >= nums[start]) {
                if(target >= nums[start] and target < nums[middle])
                    end = middle - 1;
                else
                    start = middle + 1;
            }
            // case 3: We'll find in second segment (left-right way)
            else {
                if(target > nums[middle] and target <= nums[end])
                    start = middle + 1;
                else
                    end = middle - 1;
            }
        }

        return ansIndex;
    }
};

int main() {
    int n, target;

    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> target;

    Solution sol;
    cout << sol.search(nums, target) << endl;

    return 0;
}
