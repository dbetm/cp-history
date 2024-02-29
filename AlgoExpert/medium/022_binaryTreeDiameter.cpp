#include <bits/stdc++.h>
#include "BinaryTree.h"
// solved
// tags: binary tree, recursion
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;


// diameter and height
pair<int, int> dfs(BinaryTree* tree) {
    if(!tree) return make_pair(0, 0);

    auto left = dfs(tree->left);
    auto right = dfs(tree->right);

    int maxDiameter = max(
        max(left.first, right.first), left.second + right.second
    );
    int maxHeight = max(left.second, right.second) + 1;

    return make_pair(maxDiameter, maxHeight);
}

int binaryTreeDiameter(BinaryTree* tree) {
    /*Proposal
    Time: O(n)
    Space: O(h)
    */
    auto ans = dfs(tree);

    return ans.first;
}


int main() {
    BinaryTree bt(1);

    // TEST CASE #1
    auto three = bt.insertSingle(3, true);
    auto seven = three->insertSingle(7, true);
    auto eight = seven->insertSingle(8, true);
    eight->insertSingle(9, true);

    auto four = three->insertSingle(4, false);
    auto five = four->insertSingle(5, false);
    five->insertSingle(6,false);

    bt.insertSingle(2, false);

    // TEST CASE #2
    // auto two = bt.insertSingle(2, true);
    // auto three = bt.insertSingle(3, false);


    auto ans = binaryTreeDiameter(&bt);
    watch(ans)

	return 0;
}
