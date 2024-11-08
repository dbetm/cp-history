#include <bits/stdc++.h>
// https://leetcode.com/problems/rotate-array/
// Tag(s): Arrays, implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

void printArr(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    if(k > 0) {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
}

int main() {
    fastIO
    int n, k;
    cin >> n;
    vi nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    rotate(nums, k);

    printArr(nums);

	return 0;
}
