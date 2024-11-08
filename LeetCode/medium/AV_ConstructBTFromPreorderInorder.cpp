#include <bits/stdc++.h>
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Tag(s): DS, Trees
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

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
    int getIndex(vi &vals, int start, int end, int val) {
        int index = -1;

        for (int i = start; i <= end; i++) {
            if(vals[i] == val) {
                index = i;
                break;
            }
        }

        return index;
    }

    TreeNode* buildST(vi &pre, vi &ino, int startIno, int endIno, int startPre, int endPre) {
        if(startIno > endIno || startPre > endPre) return NULL;

        int valRoot = pre[startPre];

        TreeNode* root = new TreeNode(valRoot);

        int rootIndex = getIndex(ino, startIno, endIno, valRoot);

        int startLeftInorder = startIno;
        int endLeftInorder = rootIndex - 1;
        int startLeftPreorder = startPre + 1;
        int endLeftPreorder = startLeftPreorder + (endLeftInorder - startLeftInorder);

        int startRightInorder = rootIndex + 1;
        int endRightInorder = endIno;
        int startRightPreorder = endLeftPreorder + 1;
        int endRightPreorder = endPre;

        root->left = buildST(
            pre,
            ino,
            startLeftInorder,
            endLeftInorder,
            startLeftPreorder,
            endLeftPreorder
        );
        root->right = buildST(
            pre,
            ino,
            startRightInorder,
            endRightInorder,
            startRightPreorder,
            endRightPreorder
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // int index = getIndex(inorder, 0, n-1, preorder);

        return buildST(preorder, inorder, 0, n-1, 0, n-1);
    }

    void printLevelOrder(TreeNode* root) {
        if(root == NULL) return;

        queue<TreeNode*> myQ;
        myQ.push(root);
        myQ.push(NULL);

        while(!myQ.empty()) {
            TreeNode *node = myQ.front();
            myQ.pop();

            if(node == NULL) {
                cout << endl;

                if(!myQ.empty()) myQ.push(NULL);
            }
            else {
                cout << node->val << " ";
                if(node->left) myQ.push(node->left);
                if(node->right) myQ.push(node->right);
            }
        }
    }
};

int main() {
    fastIO
    int n;
    cin >> n;
    vi preorder(n), inorder(n);
    Solution sol;

    for (int i = 0; i < n; ++i) cin >> preorder[i];
    for (int i = 0; i < n; ++i) cin >> inorder[i];

    TreeNode * tree = sol.buildTree(preorder, inorder);
    sol.printLevelOrder(tree);

	return 0;
}
