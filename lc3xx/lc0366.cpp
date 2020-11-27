//--- Q: 366. Find Leaves of Binary Tree

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        postorder(root, res);
        return res;
    }
    int postorder(TreeNode *root, vector<vector<int>> &res) {
        if (!root)
            return 0;
        int l = postorder(root->left, res);
        int r = postorder(root->right, res);
        int h = max(l, r) + 1;
        if (res.size() <= h-1)
            res.push_back({root->val});
        else
            res[h-1].push_back(root->val);
        return h;
    }
};