//--- Q: 1100. Delete Nodes And Return Forest

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
    vector<TreeNode *> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        root = postorder(root, del);
        if (root) {
            res.push_back(root);
        }
        return res;
    }
    TreeNode *postorder(TreeNode *root, unordered_set<int> &del) {
        if (root->left) {
            root->left = postorder(root->left, del);
        }
        if (root->right) {
            root->right = postorder(root->right, del);
        }
        if (del.find(root->val) != del.end()) {
            if (root->left) {
                res.push_back(root->left);
            }
            if (root->right) {
                res.push_back(root->right);
            }
            return nullptr;
        } else {
            return root;
        }
    }
};