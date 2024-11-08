#include <bits/stdc++.h>
// https://leetcode.com/problems/binary-tree-level-order-traversal/
// Tag(s): Árboles
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == NULL) return answer;

        vector<int> level;
        queue<TreeNode*> myQ;
        myQ.push(root);
        myQ.push(NULL);

        while(!myQ.empty()) {
            TreeNode *node = myQ.front();
            myQ.pop();

            if(node == NULL) {
                answer.push_back(level);
                level.clear();

                if(!myQ.empty()) {
                    myQ.push(NULL);
                }
            }
            else {
                level.push_back(node->val);
                if(node->left) myQ.push(node->left);
                if(node->right) myQ.push(node->right);
            }
        }

        return answer;
    }
};

int main() {
	return 0;
}
