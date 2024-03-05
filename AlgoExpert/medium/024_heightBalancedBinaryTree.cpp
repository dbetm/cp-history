#include <bits/stdc++.h>
#include "BinaryTree.h"
// solved
// tags: binary tree, recursion
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;

int ans = true;

int computeHeights(BinaryTree* tree, int level=0) {
    /*My solution
    Time: O(n)
    Space: O(h)
    */
    if(tree == nullptr) return 0;

    watch(tree->value);
    auto tmp = tree->value;
    int leftHeight = 0;
    int rightHeight = 0;

    if(ans) {
        leftHeight = 1 + computeHeights(tree->left, level+1);
        rightHeight = 1 + computeHeights(tree->right, level+1);

        cout << "value: " << tmp << ", left: " << leftHeight << ", right: " << rightHeight << endl;

        if(abs(leftHeight - rightHeight) > 1) {
            ans = false;
        }
    }

    return max(leftHeight, rightHeight);
}

bool heightBalancedBinaryTree(BinaryTree* tree, int level=0) {
    ans = true; 
    computeHeights(tree, 0);

    return ans;
}



int main() {
    BinaryTree bt(1);

    // TEST CASE #1
    // auto two = bt.insertSingle(2, true);
    // auto three = bt.insertSingle(3, false);
    // two->insertSingle(4, true);
    // auto five = two->insertSingle(5, false);
    // five->insertSingle(7, true);
    // five->insertSingle(8, false);
    // three->insertSingle(6, false);

    // bt.print();

    // TEST CASE #4
    // auto two = bt.insertSingle(2, true);
    // auto three = bt.insertSingle(3, false);
    // auto four = two->insertSingle(4, true);
    // four->insertSingle(6, true);
    // three->insertSingle(5, false);

    bool x = heightBalancedBinaryTree(&bt);
    watch(x)

	return 0;
}
