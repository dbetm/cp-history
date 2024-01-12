#include <bits/stdc++.h>
// solved
// tags: binary tree, dfs, recursion
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
typedef long long int lli;
lli MAX = 1e9+7;

class BinaryTree {
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;

    BinaryTree(int val);
    BinaryTree* insert(int val, bool right);
    void printTree();
};

BinaryTree::BinaryTree(int val) {
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
}

BinaryTree* BinaryTree::insert(int val, bool right) {
    if(right) {
        this->right = new BinaryTree(val);
        return this->right;
    }

    this->left = new BinaryTree(val);
    return this->left;
}

void BinaryTree::printTree() {
    queue<BinaryTree*> myQ;
    myQ.push(this);
    myQ.push(NULL);
    // we insert NULL to point the end of a level

    while(!myQ.empty()) {
        BinaryTree *node = myQ.front();
        myQ.pop();

        if(node == NULL) {
            if(!myQ.empty()) {
                myQ.push(NULL);
            }
            cout << endl;
        }
        else {
            cout << node->value << " ";
            if(node->left) myQ.push(node->left);
            if(node->right) myQ.push(node->right);
        }
    }
}

void explore(BinaryTree* node, vector<int> &ans, int currentSum) {
    if(node->left == nullptr and node->right == nullptr) {
        ans.push_back(currentSum);
    }

    if(node->left) {
        currentSum += node->left->value;
        explore(node->left, ans, currentSum);
        currentSum -= node->left->value;
    }

    if(node->right) {
        currentSum += node->right->value;
        explore(node->right, ans, currentSum);
        currentSum -= node->right->value;
    }
}

vector<int> branchSums(BinaryTree* root) {
    /*My solution:
    Time: O(n)
    Space: O(m)

    n => number of nodes
    m => number of leafs / branches
    */
    vector<int> ans;

    explore(root, ans, root->value);

    return ans;
}

int main() {
    BinaryTree bt(1);
    auto node = bt.insert(3, true);
    node->insert(7, true);
    node->insert(6, false);

    node = bt.insert(2, false);
    auto secondLevel = node->insert(5, true);
    secondLevel->insert(10, false);

    secondLevel = node->insert(4, false);
    secondLevel->insert(9, true);
    secondLevel->insert(8, false);

    //bt.printTree();

    auto ans = branchSums(&bt);

    for(auto item : ans) {
        cout << item << endl;
    }

	return 0;
}
