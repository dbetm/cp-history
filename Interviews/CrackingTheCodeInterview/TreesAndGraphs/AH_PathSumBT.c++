#include <bits/stdc++.h>
// https://leetcode.com/problems/path-sum-iii/ (SIMILAR)
// Tag(s): Trees, recursion

/* You are given a binary tree in which each node contains a value.
Design an algorithm to print all paths which sum up to that value.
Note that it can be any path in the tree - it does not have to start at the root.
*/

using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *l, TreeNode *r): val(val), left(l), right(r) {}
};

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

void inorderTraversal(TreeNode *root) {
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->val << endl;
    inorderTraversal(root->right);
}

void printPath(vi &path, int level) {
    watch(level)
    for(auto val : path) {
        cout << val << " ";
    }
    cout << endl;
}

void computePaths(TreeNode *root, int &target, int h, vi tmp, vvi &ans) {
    if(root == nullptr) return;

    tmp.push_back(root->val);

    int accumulatedSum = 0;
    for (int i = h; i >= 0; --i) {
        accumulatedSum += tmp[i];

        if(accumulatedSum == target) {
            vector<int> path;
            copy(tmp.begin()+i, tmp.begin()+h+1, back_inserter(path));
            ans.push_back(path);
        }
    }
    vector<int> a(tmp);
    vector<int> b(tmp);

    computePaths(root->left, target, h+1, a, ans);
    computePaths(root->right, target, h+1, b, ans);
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> tmp;

    computePaths(root, targetSum, 0, tmp, ans);

    return ans;
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
    //inorderTraversal(root);
    
    auto ans = pathSum(root, targetSum);
    watch(ans.size())

    for(vector<int> path : ans) {
        for(int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
