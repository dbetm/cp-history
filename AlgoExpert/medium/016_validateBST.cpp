#include <bits/stdc++.h>
// solved
// tags: BST, binary tree
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
long long int inf = 1e9+7;


class BST {
    // My solution
    public:
        int value;
        BST* left;
        BST* right;

        BST(int val) {
            value = val;
            left = nullptr;
            right = nullptr;
        }

        BST& insert(int val) {
            // Time: O(log n) | Space: O(log n)

            // left 
            if(val < this->value) {
                if(this->left == nullptr) this->left = new BST(val);
                else this->left->insert(val);
            }
            // right
            else {
                if(this->right == nullptr) this->right = new BST(val);
                else this->right->insert(val);
            }

            return *this;
        }


        void printTree() {
            queue<BST*> myQ;
            myQ.push(this);
            myQ.push(NULL);
            // we insert NULL to point the end of a level

            while(!myQ.empty()) {
                BST *node = myQ.front();
                myQ.pop();

                if(node == NULL) {
                    if(!myQ.empty()) {
                        myQ.push(NULL);
                    }
                    cout << endl;
                }
                else {
                    cout << node->value << " ";
                    if(node->left) myQ.push(node->left);
                    if(node->right) myQ.push(node->right);
                }
            }

            cout << "------------------------------" << endl;
        }
};


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
