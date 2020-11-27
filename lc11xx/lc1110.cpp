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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set;
        vector<TreeNode *> res;
        for (int i = 0; i < to_delete.size(); ++i)
            set.insert(to_delete[i]);
        root = dfs(root, res, set);
        if (root)
            res.push_back(root);
        return res;
    }
    TreeNode *dfs(TreeNode *root, vector<TreeNode *> &res, unordered_set<int> &set) {
        if (root->left)
            root->left = dfs(root->left, res, set);
        if (root->right)
            root->right = dfs(root->right, res, set);
        if (set.find(root->val) != set.end()) {
            if (root->left)
                res.push_back(root->left);
            if (root->right)
                res.push_back(root->right);
            return NULL;
        }
        return root;
    }
};