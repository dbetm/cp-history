#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> pre;
    int m = nums1.size(), n = nums2.size();
    vector<int> ans;

    pre[nums2[n-1]] = -1;

    for (int i = n-2; i >= 0; --i) {
        if(nums2[i] < nums2[i+1]) {
            pre[nums2[i]] = nums2[i+1];
        }
        else if(nums2[i] < pre[nums2[i+1]]) {
            pre[nums2[i]] = pre[nums2[i+1]];
        }
        else {
            pre[nums2[i]] = -1; // the next element in the map
        }
    }
    // compute queries
    for (int i = 0; i < m; i++) {
        ans.push_back(pre[nums1[i]]);
    }

    return ans;
}

int main() {
    fastIO
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);

    for (int i = 0; i < m; ++i) cin >> nums1[i];
    for (int i = 0; i < n; ++i) cin >> nums2[i];

    auto ans = nextGreaterElement(nums1, nums2);

    for(const int element : ans) {
        cout << element << " ";
    }
    cout << endl;

	return 0;
}
