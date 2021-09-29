#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
// https://leetcode.com/problems/subtree-of-another-tree/ modified version

/*
You have two very large binary trees: T1, with millions of nodes, and T2,
with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
*/
using namespace std;
typedef vector<int> vi;
#define watch(x) cout << (#x) << " is " << x << endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

TreeNode *genTree(vi &ino, int startIno, int endIno, vi &pre, int startPre, int endPre);
void printInorder(TreeNode *root);
int getIdxIno(vi &ino, int startIno, int endIno, int val);

class Solution {
private:
    bool compareTrees(TreeNode *t1, TreeNode *t2) {
        if(t1 == nullptr and t2 == nullptr) return true;
        else if(t1 == nullptr and t2 != nullptr) return false;
        else if(t1 != nullptr and t2 == nullptr) return true;
        else if(t1->val != t2->val) return false;

        bool ans = true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({t1, t2});

        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();

            // watch(tmp.first->val )
            // watch(tmp.second->val )

            if(tmp.first->val != tmp.second->val) {
                ans = false;
                break;
            }

            if(tmp.first->left != nullptr and tmp.second->left != nullptr) {
                q.push({tmp.first->left, tmp.second->left});
            }
            if(tmp.first->right != nullptr and tmp.second->right != nullptr) {
                q.push({tmp.first->right, tmp.second->right});
            }

            bool c1 = tmp.first->left != nullptr and tmp.second->left == nullptr;
            bool c2 = tmp.first->left == nullptr and tmp.second->left != nullptr;
            bool c3 = tmp.first->right != nullptr and tmp.second->right == nullptr;
            bool c4 = tmp.first->right != nullptr and tmp.second->right == nullptr;

            if(c1 or c2 or c3 or c4) {
                ans = false;
                break;
            }
        }

        return ans;
    }
public:
    bool isSubtree(TreeNode *root, TreeNode *subroot) {
        if(root == nullptr and subroot == nullptr) return true;
        else if(root == nullptr and subroot != nullptr) return false;
        else if(root != nullptr and subroot == nullptr) return true;

        queue<TreeNode*> q;
        TreeNode *t1 = nullptr;
        q.push(root);

        while(!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();

            if(tmp->val == subroot->val) {
                t1 = tmp;
                break;
            }

            if(tmp->left != nullptr) q.push(tmp->left);
            if(tmp->right != nullptr) q.push(tmp->right);
        }

        return this->compareTrees(t1, subroot);
    }
};

int main() {
    int nT1, nT2;
    cin >> nT1;
    vector<int> inoT1(nT1), preT1(nT1);

    for(int i = 0; i < nT1; ++i) cin >> inoT1[i];
    for(int i = 0; i < nT1; ++i) cin >> preT1[i];

    TreeNode *root = genTree(inoT1, 0, nT1-1, preT1, 0, nT1-1);
    //printInorder(root);

    cin >> nT2;
    vector<int> inoT2(nT2), preT2(nT2);

    for(int i = 0; i < nT2; ++i) cin >> inoT2[i];
    for(int i = 0; i < nT2; ++i) cin >> preT2[i];

    TreeNode *subRoot = genTree(inoT2, 0, nT2-1, preT2, 0, nT2-1);
    //printInorder(subRoot);

    Solution sol;

    cout << (!sol.isSubtree(root, subRoot) ? "No subtree" : "Yes, a subtree") << endl;

    return 0;
}

/* Generate the binary three using a recursive function with the
inorder and preorder vectors */
TreeNode *genTree(vi &ino, int startIno, int endIno, vi &pre, int startPre, int endPre) {
    // base case
    if(startIno > endIno or startPre > endPre) return nullptr;

    TreeNode *root = new TreeNode(pre[startPre]);

    int indexIno = getIdxIno(ino, startIno, endIno, pre[startPre]);

    // left subarray to build left subtree
    int leftStartIno = startIno;
    int leftEndIno = indexIno - 1;
    int leftStartPre = startPre + 1;
    int leftEndPre = leftStartPre + (leftEndIno - leftStartIno);

    // right subArray to build right subtree
    int rightStartIno = indexIno + 1;
    int rightEndIno = endIno;
    int rightStartPre = leftEndPre + 1;
    int rightEndPre = rightStartPre + (rightEndIno - rightStartIno);

    root->left = genTree(
        ino, leftStartIno, leftEndIno, pre, leftStartPre, leftEndPre
    );

    root->right = genTree(
        ino, rightStartIno, rightEndIno, pre, rightStartPre, rightEndPre
    );

    return root;
}

int getIdxIno(vi &ino, int startIno, int endIno, int val) {
    int index = 0;

    for (int i = startIno; i <= endIno; i++) {
        if(ino[i] == val) {
            index = i;
            break;
        }
    }

    return index;
}

void printInorder(TreeNode *root) {
    if(root == nullptr) return;

    printInorder(root->left);
    cout << root->val << endl;
    printInorder(root->right);
}
