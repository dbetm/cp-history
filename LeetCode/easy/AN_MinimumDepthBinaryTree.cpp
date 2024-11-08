#include <bits/stdc++.h>
// https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    struct qItem {
        TreeNode *node;
        int depth;
    };

    int minDepth(TreeNode* root) {
        int ans = 0;
        if(root == NULL) return ans;
        queue<qItem> myQ;

        qItem firstNode;
        firstNode.node = root;
        firstNode.depth = 1;

        myQ.push(firstNode);

        while(!myQ.empty()) {
            qItem item = myQ.front();
            myQ.pop();

            if(item.node->left == NULL and item.node->right == NULL) {
                ans = item.depth;
                break;
            }

            if(item.node->left) {
                qItem a;
                a.node = item.node->left;
                a.depth = item.depth + 1;
                myQ.push(a);
            }

            if(item.node->right) {
                qItem a;
                a.node = item.node->right;
                a.depth = item.depth + 1;
                myQ.push(a);
            }
        }

        return ans;
    }
};

int main() {
	return 0;
}
