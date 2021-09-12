#include <bits/stdc++.h>

using namespace std;
/*
Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a
given node in a binary search tree where each node has a link to its parent.
*/

#define watch(x) cout << (#x) << " is " << x << endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *l, TreeNode *r): val(val), left(l), right(r) {}
};

class Solution {
private:
    void inorder(TreeNode *root, vector<TreeNode*> &ino);
public:
    Solution();
    TreeNode *buildTree(vector<int> &arr, int left, int right);
    TreeNode *getNextNode(TreeNode *root, TreeNode *node);
    TreeNode *getRandomNode(TreeNode *root);
};

Solution::Solution() {}

TreeNode *Solution::buildTree(vector<int> &arr, int left, int right) {
    if(left > right) return nullptr;

    int middle = left + ((right - left) / 2);

    TreeNode *root = new TreeNode(arr[middle]);
    root->left = this->buildTree(arr, left, middle-1);
    root->right = this->buildTree(arr, middle+1, right);

    return root;
}

TreeNode *Solution::getNextNode(TreeNode *root, TreeNode *node) {
    vector<TreeNode*> inorder;
    this->inorder(root, inorder);
    TreeNode *ans = nullptr;

    int n = inorder.size();
    for (int i = 0; i < n; ++i) {
        if(inorder[i] == node and (i+1) < n) {
            ans = inorder[i+1];
            break;
        }
    }

    return ans;
}

TreeNode *Solution::getRandomNode(TreeNode *root) {

    if(root == nullptr) return nullptr;

    vector<TreeNode*> nodes;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *tmp = q.front();
        nodes.push_back(tmp);

        q.pop();

        if(tmp->left != nullptr) q.push(tmp->left);
        if(tmp->right != nullptr) q.push(tmp->right);
    }

    int n = nodes.size();
    srand(time(0));

    for (int i = 0; i < n; ++i) {
        cout << nodes[i]->val  << " ";
    }
    cout << endl;

    int index = rand() % n;
    watch(index)

    return nodes[index];
}

// Private
void Solution::inorder(TreeNode *root, vector<TreeNode*> &ino) {
    if(root == nullptr) return;

    this->inorder(root->left, ino);
    ino.push_back(root);
    this->inorder(root->right, ino);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    Solution sol;

    TreeNode *root = sol.buildTree(arr, 0, n-1);
    TreeNode *node = sol.getRandomNode(root);

    if(node != nullptr) {
        cout << "Random node, val: " << node->val << endl;
        TreeNode *nextNode = sol.getNextNode(root, node);
        if(nextNode != nullptr) cout << "Next node: " << nextNode->val << endl;
        else cout << "Next node: None" << endl;
    }
    else {
        cout << "RANDOM NODE IS NULL" << endl;
    }

    return 0;
}
