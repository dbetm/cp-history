#include <bits/stdc++.h>
#include "BinaryTree.h"
// solved
// tags: binary tree, recursion
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;


int acc;

void postOrder(BinaryTree* tree, int target, bool inversed=false) {
    if(tree == nullptr) return;

    if(acc != target) {
        if(inversed) {
            postOrder(tree->right, target, inversed);
            postOrder(tree->left, target, inversed);
        }
        else {
            postOrder(tree->left, target);
            postOrder(tree->right, target);
        }

        watch(tree->value)
        acc += (acc != target) ? tree->value : 0;
    }
}


int splitBinaryTree(BinaryTree* tree) {
    /*My solution
    Time: O(n)
    Space: O(h)
    */
    int total = 0;
    int target = 0;

    queue<BinaryTree*> q;
    q.push(tree);

    while(!q.empty()) {
        auto node = q.front();
        q.pop();

        total += node->value;

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }

    watch(total);

    if(total % 2 == 0) {
        acc = 0;
        target = int(total / 2);
        postOrder(tree, target);

        cout << "---------------" << endl;
        if(acc != target) {
            acc = 0;
            postOrder(tree, target, true);
        }

        target = (acc == target) ? target : 0;
    }

    return target;
}


int main() {
    BinaryTree bt(1);

    // TEST CASE #1
    // auto three = bt.insertSingle(3, true);
    // auto minusTwo = bt.insertSingle(-2, false);
    // auto six = three->insertSingle(6, true);
    // three->insertSingle(-5, false);
    // six->insertSingle(2, true);
    // minusTwo->insertSingle(5, true);
    // minusTwo->insertSingle(2, false);

    // TEST CASE #2
    // auto two = bt.insertSingle(2, true);
    // auto three = bt.insertSingle(3, false);

    // TEST CASE #3
    // bt.insertSingle(2, true);
    // auto one = bt.insertSingle(1, false);
    // one->insertSingle(2, false);

    // TEST CASE #17
    bt.insertSingle(9, true);
    auto twenty = bt.insertSingle(20, false);
    twenty->insertSingle(30, true);
    auto ten = twenty->insertSingle(10, false);
    ten->insertSingle(35, true);
    ten->insertSingle(15, false);

    bt.print();

    // watch(symmetricalTree(&bt));
    auto ans = splitBinaryTree(&bt);
    watch(ans);

	return 0;
}
