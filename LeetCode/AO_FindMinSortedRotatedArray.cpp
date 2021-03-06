#include <bits/stdc++.h>
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Tag(s): Binary search, implementation
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
    int findMin(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int end = n - 1;

        while(start <= end) {
            int middle = start + ((end - start) / 2);
            int next = (middle + 1) % n;
            int previus = (middle - 1 + n) % n;

            if(nums[middle] <= nums[next] and nums[middle] <= nums[previus]) {
                return nums[middle];
            }
            else if(nums[middle] < nums[end]) {
                end = middle - 1;
            }
            else {
                start = middle + 1;
            }
        }

        return -1;
    }
};

int main() {
    fastIO
    int n;
    cin >> n;
    vector<int> nums(n);
    Solution sol;

    for (int i = 0; i < n; i++)  cin >> nums[i];

    cout << sol.findMin(nums) << endl;

	return 0;
}
