#include <bits/stdc++.h>
#include "BinaryTree.h"
// solved
// tags: recursion, implementation, binary tree
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;


BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) {
    /*My solution
    Time: O(min(n, m))
    Space: O(min(h, k))

    Where n is the number of nodes in tree 1, m number of nodes in tree 2
    h the max height of tree 1 and k the max height of tree 2.
    */
    if(not tree1 and not tree2) return nullptr;

    if(tree1 and tree2) {
        tree1->value += tree2->value;
        tree1->left = mergeBinaryTrees(tree1->left, tree2->left);
        tree1->right = mergeBinaryTrees(tree1->right, tree2->right);
    }
    else if(tree2) {
        tree1 = new BinaryTree(tree2->value);

        tree1->left = tree2->left;
        tree1->right = tree2->right;
    }

    return tree1;
}


int main() {
    BinaryTree t1(1);

    // TEST CASE #1
    auto three = t1.insertSingle(3, true);
    t1.insertSingle(2, false);
    three->insertSingle(7, true);
    three->insertSingle(4, false);

    t1.print();

    BinaryTree t2(1);
    auto five = t2.insertSingle(5, true);
    auto nine = t2.insertSingle(9, false);
    five->insertSingle(2, true);
    nine->insertSingle(7, true);
    nine->insertSingle(6, false);

    t2.print();

    auto ans = mergeBinaryTrees(&t1, &t2);
    ans->print();

	return 0;
}
