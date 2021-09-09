#include <bits/stdc++.h>
/*
Given a sorted (increasing order) array, write an algorithm to create a
binary tree with minimal height.
*/
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(): val(0), right(nullptr), left(nullptr) {}
    TreeNode(int val): val(val), right(nullptr), left(nullptr) {}
};

TreeNode* buildMinBT(vector<int> &arr, int start, int end) {
    if(start > end) return nullptr;

    int middle = ((end - start) / 2) + start;
    TreeNode *root = new TreeNode(arr[middle]);
    root->left = buildMinBT(arr, start, middle-1);
    root->right = buildMinBT(arr, middle+1, end);

    return root;
}

void inorderTraversal(TreeNode *root) {
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout << "Node: " << root->val << endl;
    inorderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) cin >> arr[i];

    TreeNode *root = buildMinBT(arr, 0, n-1);

    inorderTraversal(root);

    return 0;
}
