#include <bits/stdc++.h>
// https://leetcode.com/problems/validate-binary-search-tree/
// Tag(s): Árboles, estructuras de datos
// NO COMPLETE IMPLEMENTED HERE
using namespace std;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


typedef long long int lli;
lli MAX = 1e10;

class Solution {
public:
    bool explore(TreeNode* node, lli min=-MAX, lli max=MAX) {
        if(node == NULL) return true;

        bool left = explore(node->left, min, node->val);
        bool right = explore(node->right, node->val, max);

        if(left and right and node->val > min and node->val < max) return true;

        return false;
    }

    bool isValidBST(TreeNode* root) {
        return explore(root);
    }
};

int main() {
	return 0;
}
