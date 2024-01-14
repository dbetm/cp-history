#include <bits/stdc++.h>
// solved
// tags: binary tree, dfs
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
typedef long long int lli;
lli MAX = 1e9+7;

const int ADDITION_OP = -1;
const int SUBTRACTION_OP = -2;
const int DIVISION_OP = -3;
const int MULTIPLICATION_OP = -4;


class BinaryTree {
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;

    BinaryTree(int val);
    BinaryTree* insert(int val, string side);
    void printTree();
};

BinaryTree::BinaryTree(int val) {
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
}

BinaryTree* BinaryTree::insert(int val, string side) {
    if(side == "right") {
        this->right = new BinaryTree(val);
        return this->right;
    }

    this->left = new BinaryTree(val);
    return this->left;
}

int evaluateExpressionTree(BinaryTree* tree) {
    /*My solution:
    Time: O(n)
    Space: 0(h)

    where n is the number of nodes and h the height of the tree.
    */
    if(tree->left == nullptr and tree->right == nullptr) {
        return tree->value;
    }

    int leftVal = evaluateExpressionTree(tree->left);
    int rightVal = evaluateExpressionTree(tree->right);

    if(tree->value == ADDITION_OP) return leftVal + rightVal;
    if(tree->value == SUBTRACTION_OP) return leftVal - rightVal;
    if(tree->value == DIVISION_OP) return int(leftVal / rightVal);
    if(tree->value == MULTIPLICATION_OP) return leftVal * rightVal;

    return tree->value;
}

int main() {
    const string RIGHT = "right";
    const string LEFT = "left";

    BinaryTree bt(-1);
    auto node = bt.insert(-3, RIGHT);
    node->insert(3, RIGHT);
    node->insert(8, LEFT);

    node = bt.insert(-2, LEFT);
    auto secondLevel = node->insert(2, RIGHT);

    secondLevel = node->insert(-4, LEFT);
    secondLevel->insert(3, RIGHT);
    secondLevel->insert(2, LEFT);

    cout << evaluateExpressionTree(&bt) << endl;

	return 0;
}
