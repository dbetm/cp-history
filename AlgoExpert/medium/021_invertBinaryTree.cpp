#include <bits/stdc++.h>
#include "BinaryTree.h"
// solved
// tags: binary tree, recursion
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;


void invertBinaryTree(BinaryTree* tree) {
    /*My solution
    Time: O(n)
    Space: O(h)

    where h is the height of the tree
    */
    if(tree == nullptr) return;

    auto tmpRight = tree->right;
    auto tmpLeft = tree->left;

    invertBinaryTree(tree->left);
    invertBinaryTree(tree->right);

    tree->right = tmpLeft;
    tree->left = tmpRight;
}


int main() {
    int n, cont = 0;
    cin >> n;
    vector<int> values(n);

    while(n--) {
        cin >> values[cont++];
    }

    BinaryTree bt(values[0]);
    bt.insert(values);

    bt.print();

    invertBinaryTree(&bt);
    bt.print();

	return 0;
}
