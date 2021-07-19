//--- Q: 0366. Find Leaves of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> findLeaves(TreeNode* root) {
        postorder(root);
        return res;
    }
    int postorder(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int h = max(postorder(root->left), postorder(root->right));
        if (res.size() == h) {
            res.push_back({root->val});
        } else {
            res[h].push_back(root->val);
        }
        return h+1;
    }
};