#include <bits/stdc++.h>
// https://leetcode.com/problems/path-sum/
// Tag(s): DS, Trees, math
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *l, TreeNode *r): val(val), left(l), right(r) {}
};

bool isLeaf(TreeNode *node) {
    return (node != nullptr and node->left == nullptr and node->right == nullptr);
}

void inorderTraversal(TreeNode *root) {
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->val << endl;
    inorderTraversal(root->right);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return false;
    targetSum -= root->val;
    bool ans;
    if(targetSum == 0 and isLeaf(root)) ans = true;
    else {
        ans = hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum);
    }

    return ans;
}

/* Build binary tree using vals for each level.
*/
TreeNode *buildTree(vector<TreeNode*> &tree) {
    int n = tree.size();
    if(n == 0) return nullptr;

    TreeNode *root = tree[0];
    int parentIdx = 0, cont = 1, numNULLs;
    bool isLeft = true;
    int level = 1;
    int children = 2 * level;
    int x = 0;

    while(cont < n) {
        numNULLs = 0;
        for (int i = cont; i < (cont + children); ++i, ++x) {
            if(x == 2) {
                ++parentIdx;
                x = 0;
            }
            if(tree[parentIdx] == nullptr) {
                ++parentIdx;
                --i;
                --x;
                continue;
            }
            if(isLeft) tree[parentIdx]->left = tree[i];
            else tree[parentIdx]->right = tree[i];

            if(tree[i] == nullptr) ++numNULLs;
            isLeft = !isLeft;
        }
        level++;
        cont += children;
        children = pow(2, level) - (2 * numNULLs);
    }

    return root;
}

int main() {
    int n, x, targetSum;
    string val;
    cin >> n;
    vector<TreeNode*> tree;

    for (int i = 0; i < n; i++) {
        cin >> val;
        if(val == "null") tree.push_back(nullptr);
        else {
            stringstream aux(val);
            aux >> x;
            tree.push_back(new TreeNode(x));
        }
    }
    cin.get();
    cin >> targetSum;

    TreeNode *root = buildTree(tree);

    cout << hasPathSum(root, targetSum) << endl;

    return 0;
}
