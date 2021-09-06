#include <bits/stdc++.h>
/*
Implement a function to check if a tree is balanced. For the purposes of
this question, a balanced tree is defined to be a tree such that no two
leaf nodes differ in distance from the root by more than one.
*/
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

typedef vector<int> vi;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr)  {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr)  {}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r)  {}
};

int getIndex(vi &inorder, int start, int end, int root) {
    int index = -1;

    for (int i = start; i <= end; ++i) {
        if(root == inorder[i]) {
            index = i;
            break;
        }
    }

    return index;
}

TreeNode* buildBT(vi &inorder, vi &preorder, int startIno, int endIno, int startPre, int endPre) {
    if(startIno > endIno or startPre > endPre) return NULL;

    int valRoot = preorder[startPre];
    TreeNode *root = new TreeNode(valRoot);
    int rootIndex = getIndex(inorder, startIno, endIno, valRoot);

    int leftStartIno = startIno;
    int leftEndIno = rootIndex - 1;
    int leftStartPre = startPre + 1;
    int leftEndPre = leftStartPre + (leftEndIno - leftStartIno);

    int rightStartIno = rootIndex + 1;
    int rightEndIno = endIno;
    int rightStartPre = leftEndPre + 1;
    int rightEndPre = rightStartPre + (rightEndIno - rightStartIno);

    root->left = buildBT(
        inorder, preorder,
        leftStartIno, leftEndIno,
        leftStartPre, leftEndPre
    );

    root->right = buildBT(
        inorder, preorder,
        rightStartIno,rightEndIno,
        rightStartPre, rightEndPre
    );

    return root;
}

void printPostOrder(TreeNode *root) {
    if(root == nullptr) return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->val << endl;
}

int getMaxHeightTree(TreeNode *root) {
    if(root == nullptr) return 0;

    return 1 + max(getMaxHeightTree(root->left), getMaxHeightTree(root->right));
}

bool isBalancedTree(TreeNode *root) {
    if(root == NULL or root == nullptr) return true;
    queue<TreeNode*> nodes;
    bool ans = true;

    nodes.push(root);

    while(!nodes.empty()) {
        TreeNode *currentNode = nodes.front();
        nodes.pop();

        int heightLeftSubTree = getMaxHeightTree(currentNode->left);
        int heightRightSubTree = getMaxHeightTree(currentNode->right);

        bool isBalanced = abs(heightLeftSubTree - heightRightSubTree) <= 1;

        if(!isBalanced) {
            ans = false;
            break;
        }

        if(currentNode->left != nullptr) nodes.push(currentNode->left);
        if(currentNode->right != nullptr) nodes.push(currentNode->right);
    }

    return ans;
}

bool isBalancedTree2(TreeNode *root) {
    if(root == nullptr) return true;

    int hleft = getMaxHeightTree(root->left);
    int hright = getMaxHeightTree(root->right);

    if(abs(hleft - hright) <= 1 and isBalancedTree2(root->left) and isBalancedTree2(root->right)) {
        return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), preorder(n);

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    TreeNode *root = buildBT(inorder, preorder, 0, n-1, 0, n-1);
    cout << "POST ORDER" << endl;
    printPostOrder(root);

    cout << "\nIs balanced? " << (isBalancedTree2(root) ? "Yes" : "No") << endl;

    return 0;
}
