#include <bits/stdc++.h>

using namespace std;
/*
Design an algorithm and write code to find the first common ancestor of two
nodes in a binary tree. Avoid storing additional nodes in a data structure.
NOTE: This is not necessarily a binary search tree.
*/
#define watch(x) cout << (#x) << " is " << x << endl;
#define assertm(exp, msg) assert(((void)msg, exp))

typedef vector<int> vi;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *l, TreeNode *r): val(val), left(l), right(r) {}
};

int getIndexInorder(vi &ino, int start, int end, int val);
TreeNode *buildBT(vi &ino, vi &pre, int startIno, int endIno, int startPre, int endPre);
TreeNode *getRandomNode(TreeNode *root);
TreeNode *findFirstCommonAncestor(TreeNode *root, TreeNode *a, TreeNode *b);
void traversalPostOrder(TreeNode *root);

int main() {
    int n;
    cin >> n;
    vector<int> ino(n), pre(n);

    for (int i = 0; i < n; ++i) cin >> ino[i];
    for (int i = 0; i < n; ++i) cin >> pre[i];

    TreeNode *root = buildBT(ino, pre, 0, n-1, 0, n-1);
    traversalPostOrder(root);
    cout << endl;

    TreeNode *node1 = getRandomNode(root);
    TreeNode *node2 = getRandomNode(root);

    cout << "Node #1, val: " << node1->val << endl;
    cout << "Node #2, val: " << node2->val << endl;

    TreeNode *commonAncestor = findFirstCommonAncestor(root, node1, node2);

    cout << "Common ancestor is: " << commonAncestor->val << endl;

    return 0;
}

int getIndexInorder(vi &ino, int start, int end, int val) {
    int ans = -1;

    for (int i = start; i <= end; ++i) {
        if(ino[i] == val) {
            ans = i;
            break;
        }
    }

    return ans;
}

TreeNode *buildBT(vi &ino, vi &pre, int startIno, int endIno, int startPre, int endPre) {
    if(startIno > endIno or startPre > endPre) return nullptr;
    TreeNode *root = new TreeNode(pre[startPre]);

    int index = getIndexInorder(ino, startIno, endIno, root->val);

    int leftStartIno = startIno;
    int leftEndIno = index - 1;
    int leftStartPre = startPre + 1;
    int leftEndPre = leftStartPre + (leftEndIno - leftStartIno);

    int rightStartIno = index + 1;
    int rightEndIno = endIno;
    int rightStartPre = leftEndPre + 1;
    int rightEndPre = rightStartPre + (rightEndIno - rightStartIno);

    root->left = buildBT(
        ino, pre, leftStartIno, leftEndIno, leftStartPre, leftEndPre
    );
    root->right = buildBT(
        ino, pre, rightStartIno, rightEndIno, rightStartPre, rightEndPre
    );

    return root;
}

TreeNode *getRandomNode(TreeNode *root) {
    assertm(root != nullptr, "Builded tree has a problem");

    vector<TreeNode*> nodes;
    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()) {
        TreeNode *tmp = q.front();
        q.pop();

        nodes.push_back(tmp);

        if(tmp->left != nullptr) {
            q.push(tmp->left);
        }
        if(tmp->right != nullptr) {
            q.push(tmp->right);
        }
    }

    int n = nodes.size();

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned int> dis;

    int index = dis(gen) % n;

    return nodes[index];
}

TreeNode *findFirstCommonAncestor(TreeNode *root, TreeNode *a, TreeNode *b) {
    // base cases
    if(root == nullptr) return nullptr;

    if(root == a or root == b) return root;

    TreeNode *leftSubtree = findFirstCommonAncestor(root->left, a, b);
    TreeNode *rightSubtree = findFirstCommonAncestor(root->right, a, b);

    if(leftSubtree and rightSubtree) return root;

    if(leftSubtree) return leftSubtree;

    return rightSubtree;
}

void traversalPostOrder(TreeNode *root) {
    if(root == nullptr) return;

    traversalPostOrder(root->left);
    traversalPostOrder(root->right);
    cout << root->val << " ";
}
