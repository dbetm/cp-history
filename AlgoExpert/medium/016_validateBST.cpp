#include <bits/stdc++.h>
#include "BST.h"
// solved
// tags: BST, binary tree
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
long long int inf = 1e9+7;


bool validateBst(BST* tree, long long int min=-inf, long long int max=inf) {
    /*Proposal
    Time: O(n)
    Space: O(h)

    where h is the high of the BST.
    */
    if(tree == nullptr) return true;

    auto tmpMax = max;
    auto tmpMin = min;

    return (
        tree->value < max and tree->value >= min 
        and validateBst(tree->left, min=tmpMin, max=tree->value)
        and validateBst(tree->right, min=tree->value, max=tmpMax)
    );
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
    auto isValid = validateBst(&bst);
    cout << endl;

    cout << "is valid? " << ((isValid) ? "YES": "NO") << endl;

	return 0;
}
