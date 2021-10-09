#include <bits/stdc++.h>
//
// Tag(s):
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

void rotateArray(vector<int>& nums, int k, int left) {
    int n = nums.size();

    if(left >= n-1) return;
    watch(left)
    int right = n - min(left, n-k);

    int delta = min(k, n-left);
    for (int i = 0; i < delta; ++i, ++left, ++right) {
        swap(nums[left], nums[right]);
    }

    printArr(nums);

    rotateArray(nums, k, left);
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    printArr(nums);
    rotateArray(nums, k, 0);

    // for (right = n - k; right < n; ++right, ++left) {
    //     swap(nums[left], nums[right]);
    // }
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

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

	return 0;
}
