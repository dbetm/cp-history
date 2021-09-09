#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;
/*
Given a binary search tree, design an algorithm which creates a linked list
of all the nodes at each depth (i.e., if you have a tree with depth D,
you’ll have D linked lists).
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(-1), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildBST(vector<int> &arr, int start, int end) {
    if(start > end) return nullptr;

    int middle = ((end - start) / 2) + start;
    TreeNode *root = new TreeNode(arr[middle]);
    root->left = buildBST(arr, start, middle-1);
    root->right = buildBST(arr, middle+1, end);

    return root;
}

void preorderTraversal(TreeNode *root) {
    if(root == nullptr) return;

    cout << "Node: " << root->val << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void printLinkedLists(ListNode *lists[], int levels) {
    for (int i = 0; i < levels; ++i) {
        ListNode *tmp = lists[i];
        while(tmp != nullptr) {
            cout << tmp->val << "<-";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

void generateLinkedLists(TreeNode *root, int level, ListNode *lists[]) {
    if(root == nullptr) return;
    //watch(level)
    if(lists[level]->val == -1) lists[level]->val = root->val;
    else {
        ListNode *tmp = lists[level];
        while(tmp != nullptr and tmp->next != nullptr) {
            tmp = tmp->next;
        }
        ListNode *node = new ListNode(root->val);
        tmp->next = node;
    }
    //printLinkedLists(lists, 3);
    generateLinkedLists(root->left, level + 1, lists);
    generateLinkedLists(root->right, level + 1, lists);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int levels = ceil(log2(n));
    ListNode *lists[levels];

    for (int i = 0; i < levels; ++i) lists[i] = new ListNode;

    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());

    TreeNode *root = buildBST(arr, 0, n-1);
    //preorderTraversal(root);
    generateLinkedLists(root, 0, lists);
    printLinkedLists(lists, levels);

    return 0;
}
