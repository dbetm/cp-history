#include <bits/stdc++.h>
#include "BST.h"
// solved
// tags: bst, recursion, binary tree
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;

int64_t inf = 1e9+7;


void insert(BST* tree, int value) {
    if(tree->left == nullptr and value < tree->value) {
        tree->left = new BST(value);
        return;
    }
    else if(tree->right == nullptr and value >= tree->value) {
        tree->right = new BST(value);
        return;
    }

    if(value < tree->value) return insert(tree->left, value);
    else insert(tree->right, value);
}

BST* reconstructBst(vector<int> preOrderTraversalValues) {
    /*My solution
    Time: O(n^2)
    Space: O(h)
    */
    int n = preOrderTraversalValues.size();
    BST* tree = new BST(preOrderTraversalValues[0]);
    auto tmp = tree;

    for(int i = 1; i < n; ++i) {
        insert(tree, preOrderTraversalValues[i]);
    }

    return tree;
}

int idx = 0;

BST* build(BST* tree, vector<int> preOrder, int64_t min, int64_t max) {
    if(idx >= preOrder.size() or preOrder[idx] < min or preOrder[idx] >= max) return nullptr;

    int tmpMax = max;
    int tmpMin = min;
    watch(tmpMax)
    watch(tmpMin)

    tree = new BST(preOrder[idx]);
    idx += 1;

    tree->left = build(tree->left, preOrder, tmpMin, tree->value);
    tree->right = build(tree->right, preOrder, tree->value, tmpMax);

    return tree;
}


BST* reconstructBst2(vector<int> preOrderTraversalValues) {
    /*Proposal
    Time: O(n)
    Space: O(h)

    h could be n for non-balanced trees, actually, the space is O(n) because of the space
    used by the n nodes, but we are focusing in the construction process.
    */
    idx = 0;
    BST* tree = nullptr;

    tree = build(nullptr, preOrderTraversalValues, -inf, inf);

    return tree;
}


int main() {
    int n;
    cin >> n;
    vector<int> preOrder(n);

    for(int i = 0; i < n; i++) {
        cin >> preOrder[i];
    }

    auto bst = reconstructBst(preOrder);

    bst->printTree();

    cout << "SECOND SOLUTION" << endl;

    bst = reconstructBst2(preOrder);
    //cout << bst << endl;
    bst->printTree();

	return 0;
}
