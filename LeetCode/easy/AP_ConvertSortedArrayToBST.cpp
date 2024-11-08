#include <bits/stdc++.h>
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Tag(s): Trees, DS
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* build(vi &nums, int start, int end) {
        if(start > end) return NULL;

        int middle = (end + start) / 2;
        TreeNode *root = new TreeNode(nums[middle]);

        root->left = build(nums, start, middle - 1);
        root->right = build(nums, middle + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();

        return build(nums, 0, n-1);
    }

    void printLevelOrder(TreeNode* root) {
        if(root == NULL) return;

        queue<TreeNode*> myQ;
        myQ.push(root);
        myQ.push(NULL);

        while(!myQ.empty()) {
            TreeNode *node = myQ.front();
            myQ.pop();

            if(node == NULL) {
                cout << endl;

                if(!myQ.empty()) myQ.push(NULL);
            }
            else {
                cout << node->val << " ";
                if(node->left) myQ.push(node->left);
                if(node->right) myQ.push(node->right);
            }
        }
    }
};

int main() {
    fastIO
    int n;
    Solution sol;

    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    TreeNode *root = sol.sortedArrayToBST(nums);

    sol.printLevelOrder(root);

	return 0;
}
