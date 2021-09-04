#include <bits/stdc++.h>

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

int getIndex(vi inorder, int start, int end, int root) {
    int index = -1;



    return index;
}

TreeNode* buildBT(vi &inorder, vi &preorder, int startIno, int endIno, int startPre, int endPre) {
    if(startIno > endIno or startPre > endPre) return NULL;

    int valRoot = preorder[startPre];
    TreeNode *root = new TreeNode(valRoot);


    return root;
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

    return 0;
}
