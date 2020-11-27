//--- Q: 1430. Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr, int idx = 0) {
        if (!root) {
            return false;
        }
        if (root->val == arr[idx]) {
            if (idx+1 == arr.size()) {
                return !root->left && !root->right ? true : false;
            } else {
                return isValidSequence(root->left, arr, idx+1) || isValidSequence(root->right, arr, idx+1);
            }
        } else {
            return false;
        }
    }
};