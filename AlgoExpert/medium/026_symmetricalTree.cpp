#include <bits/stdc++.h>
#include "BinaryTree.h"
// solved
// tags: binary tree, recursion
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;


void invertBinaryTree(BinaryTree* tree) {
    if(tree == nullptr) return;

    auto tmpRight = tree->right;
    auto tmpLeft = tree->left;

    invertBinaryTree(tree->left);
    invertBinaryTree(tree->right);

    tree->right = tmpLeft;
    tree->left = tmpRight;
}

bool sameSubtree = true;

bool checkEqualTrees(BinaryTree* t1, BinaryTree* t2) {
    if(not t1 and not t2) return true;
    if(not t1 or not t2) {
        sameSubtree = false;
        return false;
    }

    if(t1->value != t2->value) {
        sameSubtree = false;
        return false;
    }

    if(sameSubtree) {
        return (
            checkEqualTrees(t1->left, t2->left)
            and checkEqualTrees(t1->right, t2->right) 
        );
    }

    return sameSubtree;
}

bool symmetricalTree(BinaryTree* tree) {
    /*My solution
    Time: O(n)
    Space: O(h)


    The proposal alternative solution is perform DFS in left and right subtrees.
    In the right subtree the DFS will be reversed compared to left subtree.
    */

    // Missin: clone tree->left -- since the description problem don's say something about mutate the input tree
    sameSubtree = true;
    invertBinaryTree(tree->left);

    return checkEqualTrees(tree->left, tree->right);
}


bool symmetricalTree2(BinaryTree* tree) {
    bool ans = true;

    stack<BinaryTree*> leftTree;
    stack<BinaryTree*> rightTree;

    leftTree.push(tree->left);
    rightTree.push(tree->right);

    while(!leftTree.empty()) {
        auto left = leftTree.top();
        auto right = rightTree.top();

        leftTree.pop();
        rightTree.pop();

        if(not left and not right) continue;
        if((not left or not right) or (left->value != right->value)) {
            watch(left->value)
            watch(right->value)
            ans = false;
            break;
        } 

        leftTree.push(left->left);
        leftTree.push(left->right);
        rightTree.push(right->right);
        rightTree.push(right->left);

    }

    return ans;
}


int main() {
    BinaryTree bt(1);

    // TEST CASE #1
    auto two1 = bt.insertSingle(2, true);
    auto two2 = bt.insertSingle(2, false);
    auto three1 = two1->insertSingle(3, true);
    three1->insertSingle(5, true);
    three1->insertSingle(6, false);
    two1->insertSingle(4, false);

    two2->insertSingle(4, true);
    auto three2 = two2->insertSingle(3, false);
    three2->insertSingle(6, true);
    three2->insertSingle(5, false);

    // TEST CASE #2
    // auto two1 = bt.insertSingle(2, true);
    // auto two2 = bt.insertSingle(2, false);

    bt.print();

    // watch(symmetricalTree(&bt));
    watch(symmetricalTree2(&bt));

	return 0;
}
