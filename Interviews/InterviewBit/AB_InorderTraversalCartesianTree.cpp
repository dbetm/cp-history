#include <bits/stdc++.h>
// https://www.interviewbit.com/old/problems/inorder-traversal-of-cartesian-tree/
// Tag(s): Binary tree, recursivity
using namespace std;

/**
 * Definition for binary tree
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build(vector<int> &A, int start, int end) {
    if(start >= end) return NULL;

    int max = A[start];
    int maxIndex = start;
    for(int i = start; i < end; i++) {
        if(max < A[i]) {
            max = A[i];
            maxIndex = i;
        }
    }

    TreeNode* root = new TreeNode(max);
    root->left = build(A, start, maxIndex);
    root->right = build(A, maxIndex+1, end);

    return root;
}

TreeNode* buildTree(vector<int> &A) {
    return build(A, 0, A.size());
}

// Pre-order
void printTree(TreeNode* root) {
    if(root == NULL) return;

    printTree(root->left);
    cout << root->val << endl;
    printTree(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> inorder(n);

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    TreeNode *res = buildTree(inorder);

    printTree(res);

    return 0;
}
