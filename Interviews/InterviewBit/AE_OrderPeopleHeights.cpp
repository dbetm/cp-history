#include <bits/stdc++.h>
// https://www.interviewbit.com/problems/order-of-people-heights/
// Tag(s): Implementation, arrays
using namespace std;

class Solution {
public:
    Solution();
    vector<int> order(vector<int> &A, vector<int> &B);
};

Solution::Solution() {}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    // A = {5, 3, 2, 6, 1, 4} -> {[1], [2], [3], [4], [5], 6}
    // B = {0, 1, 2, 0, 3, 2} -> {[3], [2], [1], [2], [0], 0}
    //                     ans = {5, 3, 2, 1, 6, 4}
    int n = A.size();
    vector<int> ans(n);
    vector<pair<int, int>> tmp(n);
    for(int i = 0; i < n; i++) tmp[i] = {A[i], B[i]};

    sort(tmp.begin(), tmp.end());

    vector<int> indices(n);
    for(int i = 0; i < n; i++) indices[i] = i;

    for(int i = 0; i < n; i++) {
        ans[indices[tmp[i].second]] = tmp[i].first;
        indices.erase(
            indices.begin()+tmp[i].second, indices.begin()+tmp[i].second+1
        );
    }

    return ans;
}

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> heights(n);
    vector<int> infront(n);

    for (int i = 0; i < n; i++) cin >> heights[n];
    for (int i = 0; i < n; i++) cin >> infront[i];

    vector<int> ans = sol.order(heights, infront);

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
