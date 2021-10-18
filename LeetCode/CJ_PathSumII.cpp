#include <bits/stdc++.h>
// https://leetcode.com/problems/path-sum-ii/
// Tag(s): DS, Backtracking
using namespace std;

// Definition for a binary tree node.
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
    vector<vector<int>> ans;

    bool isLeaf(TreeNode *root) {
        return root->left == nullptr and root->right == nullptr;
    }

    void dfs(TreeNode *root, int target, vector<int> &path) {
        if(root == nullptr) return;

        path.push_back(root->val);
        target = target - root->val;

        if(isLeaf(root) and target == 0) {
            ans.push_back(path);
            return;
        }
        else {
            dfs(root->left, target, path);
            dfs(root->right, target, path);
        }

        path.pop_back(); // backtracking
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return ans;
        vector<int> path;

        dfs(root, targetSum, path);

        return ans;
    }
};

int main() {
    return 0;
}
