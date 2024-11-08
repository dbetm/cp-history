#include <bits/stdc++.h>
// https://leetcode.com/problems/diameter-of-binary-tree/
// Tag(s): Árboles, estructuras de datos
// NO COMPLETE IMPLEMENTED HERE
using namespace std;

std::vector<int> v;
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

class Solution {
public:
    pair<int, int> getHeightAndDiameter(TreeNode* root) {
        if(root == NULL) return make_pair(0, 0);

        pair<int, int> leftST = getHeightAndDiameter(root->left);
        pair<int, int> rightST = getHeightAndDiameter(root->right);

        int height = 1 + max(leftST.first, rightST.first);
        int diameter = max(leftST.first + rightST.first, max(leftST.second, rightST.second));

        return make_pair(height, diameter);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> ans = getHeightAndDiameter(root);

        return ans.second;
    }
};

int main() {
	return 0;
}
