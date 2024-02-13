#include <bits/stdc++.h>
// solved
// tags: binary tree, bst
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;


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

        bool contains(int val) {
            // Time: O(log n) | Space: O(log n)
            if(this->value == val) return true;
            else if(val < this->value and this->left) return this->left->contains(val);
            else if(this->right) return this->right->contains(val);

            return false;
        }

        BST& remove(int val) {
            /*
            Find the node to remove: Time: O(log n) | Space: O(1)
            Case 1: Time: O(1) | Space: O(1)
            Case 2: Time: O(1) | Space: O(1)
            Case 3: Time(height) | Space: O(1)

            When the tree is completely unbalanced, then find the node to remove is O(n) in time
            */

            cout << "removing" << val << endl;
            // check if the tree is a single-node tree
            if(!this->left and !this->right) {
                return *this;
            }

            // find the node to remove
            BST *parent = nullptr;
            BST *node = this;
            bool found = false;

            while(true) {
                if(val == node->value) {
                    found = true;
                    break;
                }
                else if(val < node->value) {
                    if(node->left) {
                        parent = node;
                        node = node->left;
                    }
                    else break;
                }
                else {
                    if(node->right) {
                        parent = node;
                        node = node->right;
                    }
                    else break;
                }
            }

            if(!found) {
                return *this;
            }

            // Borrar según tres casos
            // #1 - Es una hoja
            if(node->left == nullptr and node->right == nullptr) {
                cout << "case #1" << endl;
                if(parent->left == node) parent->left = nullptr;
                else parent->right = nullptr;
            }
            // #2 - El nodo solo tiene un hijo
            else if(node->left and node->right == nullptr) {
                cout << "case #2.1 - ";
                if(node == this) {
                    this->value = node->left->value;
                    this->right = node->left->right;
                    this->left = node->left->left;
                    cout << "done" << endl;
                }
                else if(parent->left == node) parent->left = node->left;
                else parent->right = node->left;
            }
            else if(node->left == nullptr and node->right) {
                cout << "case #2.2 - ";
                if(node == this) {
                    this->value = node->right->value;
                    this->left = node->right->left;
                    this->right = node->right->right;
                    cout << "done" << endl;
                }
                else if(parent->left == node) parent->left = node->right;
                else parent->right = node->right;
            }
            // #3 - the node has two children
            else {
                cout << "case #3" << endl;
                // find successor
                BST *successor = node->right;
                BST *parentSuccessor = node;

                while(true) {
                    // don't have left leaf
                    if(successor->left == nullptr) {
                        break;
                    }
                    parentSuccessor = successor;
                    successor = successor->left;
                }
                // swap values between successor and node
                int tmp = node->value;
                node->value = successor->value;
                successor->value = tmp;

                if(parentSuccessor == node) {
                    parentSuccessor->right = nullptr;
                }
                else {
                    parentSuccessor->left = nullptr;
                }
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


int main() {
    BST bst(10);
    bst.insert(5);
    bst.printTree();
    bst.remove(10);
    bst.printTree();
    cout << "contains " << bst.contains(15) << endl;

    // bst.insert(2).insert(5).insert(13).insert(22);
    // bst.insert(1).insert(14);

    // bst.printTree();

    // bst.insert(12);
    // bst.printTree();
    // bst.remove(10);
    // bst.printTree();
    // cout << bst.contains(15) << endl;

	return 0;
}
