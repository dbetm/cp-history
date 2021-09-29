#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int a = nums[0];
    int n = nums.size();

    for (int i = 0; i < (2*n/3); ++i) {

    }
}


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; ++i) cin >> nums[i];

    vector<int> ans = majorityElement(nums);

    for(auto num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
