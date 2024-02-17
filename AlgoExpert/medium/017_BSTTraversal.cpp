#include <bits/stdc++.h>
#include "BST.h"
// solved
// tags: bst, binary tree, traversal
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;

/*My solution:
-------------------------------------------------
Time: O(n)
Space: O(n)
*/

void inOrderTraverse(BST* tree, vector<int>& array) {
    /* The idea is first explore left branches, then get the current value
    and finally explore right branches.
    */
    if(tree == nullptr) return;

    inOrderTraverse(tree->left, array);
    array.push_back(tree->value);
    inOrderTraverse(tree->right, array);
}

void preOrderTraverse(BST* tree, vector<int>& array) {
    /* The idea is first get the current value then explore left branches
    and finally explore right branches.
    */
    if(tree == nullptr) return;

    array.push_back(tree->value);
    preOrderTraverse(tree->left, array);
    preOrderTraverse(tree->right, array);
}

void postOrderTraverse(BST* tree, vector<int>& array) {
    /* The idea is first explore left branches, then explore right branches
    and finally get the current value.
    */
    if(tree == nullptr) return;

    postOrderTraverse(tree->left, array);
    postOrderTraverse(tree->right, array);

    array.push_back(tree->value);
}


int main() {
    int root, n;
    cin >> n;
    cin >> root;
    BST bst(root);

    n--;

    while(n--) {
        int value;
        cin >> value;
        bst.insert(value);
    }

    bst.printTree();

    vector<int> inOrder;
    inOrderTraverse(&bst, inOrder);
    cout << "in order" << endl;
    for(auto item : inOrder) {
        cout << item << ", ";
    }
    cout << endl;

    vector<int> preOrder;
    preOrderTraverse(&bst, preOrder);
    cout << "pre order" << endl;
    for(auto item : preOrder) {
        cout << item << ", ";
    }
    cout << endl;

    vector<int> postOrder;
    postOrderTraverse(&bst, postOrder);
    cout << "post order" << endl;
    for(auto item : postOrder) {
        cout << item << ", ";
    }
    cout << endl;

	return 0;
}
