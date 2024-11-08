#include <bits/stdc++.h>
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL) {
            if(root->val > p->val and root->val > q->val) root = root->left;
            else if(root->val < p->val and root->val < q->val) root = root->right;
            else break;
        }

        return root;
    }
};

int main() {
	return 0;
}
