#include <bits/stdc++.h>
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Tag(s): Binary search, arrays
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
private:
    int getIndex(vector<int>& nums, int start, int end, int target, bool isFirst) {
        int ans = -1;

        while(start <= end) {
            int middle = start + ((end - start) / 2);
            if(nums[middle] == target) {
                ans = middle;
                if(isFirst) --end;
                else ++start;
            }
            else if (nums[middle] > target) {
                end = middle - 1;
            }
            else {
                start = middle + 1;
            }
        }

        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);

        int first = this->getIndex(nums, 0, nums.size()-1, target, true);
        if(first == -1) {
            return ans;
        }
        int second = this->getIndex(nums, first, nums.size()-1, target, false);

        ans[0] = first;
        ans[1] = second;

        return ans;
    }
};

int main() {
    fastIO
    int n,target;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> target;
    Solution sol;
    vector<int> ans = sol.searchRange(arr, target);

    cout << ans[0] << " " << ans[1] << endl;

	return 0;
}
