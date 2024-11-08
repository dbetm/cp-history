#include <bits/stdc++.h>
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Tag(s): Data structures, trees
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void inorder(TreeNode *root, int &cont, int &k, int &ans) {
        if(root == nullptr) return;

        inorder(root->left, cont, k, ans);
        cont++;
        if(cont == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, cont, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int cont  = 0;
        inorder(root, cont, k, ans);

        return ans;
    }
};

TreeNode* buildBST(vector<int> &nodes) {
    int n = nodes.size();

    if(n == 0) return NULL;

    TreeNode *root = new TreeNode(nodes[0]);

    for (int i = 1; i < n; ++i) {
        TreeNode *tmp = root;
        while(true) {
            if(tmp->val >= nodes[i]) {
                if(tmp->left == nullptr) {
                    tmp->left = new TreeNode(nodes[i]);
                    break;
                }
                else tmp = tmp->left;
            }
            else {
                if(tmp->right == nullptr) {
                    tmp->right = new TreeNode(nodes[i]);
                    break;
                }
                else tmp = tmp->right;
            }
        }
    }

    return root;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> nodes(n);

    for (int i = 0; i < n; ++i) cin >> nodes[i];
    cin >> k;

    TreeNode *root = buildBST(nodes);
    // watch(root)
    Solution sol;
    int kthSmallest = sol.kthSmallest(root, k);
    cout << kthSmallest << endl;

    return 0;
}
