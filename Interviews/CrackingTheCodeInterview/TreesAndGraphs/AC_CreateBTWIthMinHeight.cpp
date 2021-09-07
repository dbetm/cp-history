#include <bits/stdc++.h>

using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(): val(0), right(nullptr), left(nullptr) {}
};

TreeNode* buildMinBT(vector<int> &arr, int start, int end) {
    return nullptr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];

    TreeNode *root = buildMinBT(arr, 0, n-1);

    return 0;
}
