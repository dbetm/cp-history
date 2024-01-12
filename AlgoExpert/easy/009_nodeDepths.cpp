#include <bits/stdc++.h>
// solved
// tags: bfs, binary tree
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
typedef long long int lli;
lli MAX = 1e9+7;

class BinaryTree {
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;

    BinaryTree(int val);
    BinaryTree* insert(int val, bool right);
    void printTree();
};

BinaryTree::BinaryTree(int val) {
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
}

BinaryTree* BinaryTree::insert(int val, bool right) {
    if(right) {
        this->right = new BinaryTree(val);
        return this->right;
    }

    this->left = new BinaryTree(val);
    return this->left;
}


int nodeDepths(BinaryTree* root) {
    /*My solution:
    Time: O(n)
    Space: O(max_elements_by_level | n - in the worst case)
    */
    queue<BinaryTree*> q;
    q.push(root);
    q.push(NULL);
    int elementsByLevel = 0;
    int level = 0;
    long int accSum = 0;

    while(!q.empty()) {
        BinaryTree* node = q.front();
        q.pop();

        if(node == NULL) {
            if(!q.empty()) q.push(NULL);

            accSum += elementsByLevel * level;
            level += 1;
            elementsByLevel = 0;
        }
        else {
            elementsByLevel += 1;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    return accSum;
}

int main() {
    BinaryTree bt(1);
    auto node = bt.insert(3, true);
    node->insert(7, true);
    node->insert(6, false);

    node = bt.insert(2, false);
    auto secondLevel = node->insert(5, true);

    secondLevel = node->insert(4, false);
    secondLevel->insert(9, true);
    secondLevel->insert(8, false);

    cout << nodeDepths(&bt) << endl;

	return 0;
}
