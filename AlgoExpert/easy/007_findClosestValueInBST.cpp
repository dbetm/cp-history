#include <bits/stdc++.h>
// solved
// tags: bst, recursion
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
typedef long long int lli;
lli MAX = 1e9+7;

class BST {
    public:
        int value;
        BST* left;
        BST* right;

    BST(int val);
    BST& insert(int val);
    void printTree();
};

BST::BST(int val) {
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
}

BST& BST::insert(int val) {
    if(val < this->value) {
        if(this->left == nullptr) this->left = new BST(val);
        else this->left->insert(val);
    }
    else {
        if(this->right == nullptr) this->right = new BST(val);
        else this->right->insert(val);
    }

    return *this;
}

void BST::printTree() {
    queue<BST*> myQ;
    myQ.push(this);
    myQ.push(NULL);
    // we insert NULL to point the end of a level

    while(!myQ.empty()) {
        BST *node = myQ.front();
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

int findClosestValueInBst(BST* tree, int target) {
    /*My solution
    >>> Average (a tree more or less balanced):
    Time: O(log(n))
    Space: O(1)
    >>> Worst (a non-balanced tree):
    Time: O(n)
    Space: O(1)

    Where n is the number of nodes.
    */
    BST *node = tree;
    int ans = -1;
    int diff = MAX;

    while(node) {
        if(abs(target - node->value) < diff) {
            ans = node->value;
            diff = abs(target - node->value);
        }

        if(node->value > target) node = node->left;
        else node = node->right;
    }

    return ans;
}

int main() {
    BST bst(10);
    bst.insert(5).insert(15);
    bst.insert(2).insert(5).insert(13).insert(22);
    bst.insert(1).insert(14);

    int target = 3;

    // bst.printTree();
    cout << findClosestValueInBst(&bst, target) << endl;

	return 0;
}
