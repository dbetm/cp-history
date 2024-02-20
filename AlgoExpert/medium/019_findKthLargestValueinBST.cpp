#include <bits/stdc++.h>
#include "BST.h"
// solved
// tags: binary search, bst, recursion, traversal
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;

// TODO: Watch the video explanation
// First proposal not implemented here: use in-order traversal, savel all node values and 
// as the values are sorted increasing, so return the k largest from the end.

int findKthLargestValueInBst(BST* tree, int k) {
    /*My solution:
    Time: O(n*log(n))
    Space: O(n)
    */
    queue<BST*> myQ;
    myQ.push(tree);
    vector<int> allItems;

    while(!myQ.empty()) {
        BST* node = myQ.front();
        myQ.pop();

        allItems.push_back(node->value);
        watch(node->value)
        if(node->right) myQ.push(node->right);
        if(node->left) myQ.push(node->left);
    }

    sort(allItems.begin(), allItems.end());
    int n = allItems.size();

    // Write your code here.
    return allItems[n-k];
}


int findKthLargestValueInBst2(BST* tree, int k) {
    // don't work for all cases
    int ans = -1;
    bool notFound = true;
    stack<BST*> st;
    st.push(tree);
    cout << "insert: " << tree->value << endl;

    if(tree->left == nullptr and tree->right == nullptr) {
        return tree->value;
    }

    if(tree->right) tree = tree->right;
    else if(tree->left) {
        tree = tree->left;
        k--;

        if(k == 0) return tree->value;
    }

    while(!st.empty() and notFound) {
        cout << "insert: " << tree->value << endl;
        st.push(tree);

        bool isLeaf = st.top()->right == nullptr and st.top()->left == nullptr; 

        if(isLeaf) {
            cout << "backtracking" << endl;

            while(!st.empty()) {
                auto node = st.top();
                st.pop();

                k -= 1;
                cout << "checking: " << node->value << endl;
                if(k == 0) {
                    ans = node->value;
                    notFound = false;
                    break;
                }

                if(node->left) {
                    tree = node->left;
                    break;
                }
            }
        }
        else {
            if(tree->right) tree = tree->right;
            else if(tree->left) {
                tree = tree->left;

                k--;
                if(k == 0) {
                    ans = tree->value;
                    notFound = false;
                }
            }
        }
    }

    return ans;
}


void inOrderReversal(BST* tree, int k, int* cont, int* lastVisited) {
    if(tree == nullptr or *cont >= k) return;

    inOrderReversal(tree->right, k, cont, lastVisited);

    if(*cont < k) {
        *lastVisited = tree->value;
        *cont += 1;
        watch(*lastVisited)
        watch(*cont)
        cout << "-----" << endl;

        inOrderReversal(tree->left, k, cont, lastVisited);
    }
}

int findKthLargestValueInBst3(BST* tree, int k) {
    /*Proposal
    Time: O(k + h)
    Space: O(h)

    Where h is the height (depth) of the tree
    */
    int cont = 0;
    int* ptrCont = &cont;
    int lastVisited = -1;
    int* ptrLastVisited = &lastVisited;

    inOrderReversal(tree, k, ptrCont, ptrLastVisited);

    return lastVisited;
}


int main() {
    int root, n, k;
    cin >> n;
    cin >> root;
    BST bst(root);

    n--;

    while(n--) {
        int value;
        cin >> value;
        bst.insert(value);
    }
    cin >> k;

    bst.printTree();

    int ans = findKthLargestValueInBst(&bst, k);
    cout << ans << endl;

    ans = findKthLargestValueInBst3(&bst, k);
    cout << ans << endl;

	return 0;
}
