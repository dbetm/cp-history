#include <bits/stdc++.h>
#include "BinaryTreeLinked.h"
// solved
// tags: binary tree, recursion
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;



BinaryTreeLinked* findSuccessor(BinaryTreeLinked* tree, BinaryTreeLinked* node) {
    /*My proposal

    Time: O(n)
    Space: O(1)
    */
    if(node->right) {
        // search for the next leaf
        tree = node->right;
        while(true) {
            if(tree->left) tree = tree->left;
            else if(tree->right) tree = tree->right;
            else break;
        }
        return tree;
    };
    // it's leaf
    if(node->left == nullptr and node->right == nullptr) {
        if(node->parent == nullptr) return nullptr;
        if(node->parent->left == node) return node->parent;

        return node->parent->parent;
    }

    // it's the left child
    return node->parent;
}


int main() {
    BinaryTreeLinked bt(1);

    // TEST CASE #1
    auto two = bt.insertSingle(2, true);
    auto three = bt.insertSingle(3, false);
    auto four = two->insertSingle(4, true);
    auto six = four->insertSingle(6, true);
    auto five = two->insertSingle(5, false);
    bt.print();

    //cout << "target: " << four << endl;
    auto ans = findSuccessor(&bt, three);
    
    if(ans) {
        watch(ans->value);
    }
    else watch(ans);

	return 0;
}
