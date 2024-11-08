#include <bits/stdc++.h>
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> myQ;
        bool fromLeftToRigth = true;
        int size, index;

        myQ.push(root);

        while(!myQ.empty()) {
            size = myQ.size();
            vector<int> level(size);

            for(int i = 0; i < size; ++i) {
                TreeNode* aux = myQ.front();
                myQ.pop();

                index = (fromLeftToRigth) ? i : (size-1-i);

                level[index] = aux->val;

                if(aux->left) myQ.push(aux->left);
                if(aux->right) myQ.push(aux->right);
            }

            fromLeftToRigth = !fromLeftToRigth;

            ans.push_back(level);
        }

        return ans;
    }
};

int main() {
	return 0;
}
