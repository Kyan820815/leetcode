//--- Q: 0652. Find Duplicate Subtrees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder with recording string
class Solution {
public:
    unordered_map<string, int> map;
    vector<TreeNode *> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        postorder(root);
        return res;
    }
    string postorder(TreeNode *root) {
        string lstr = "", rstr = "", cstr = "";
        if (root->left) {
            lstr = postorder(root->left);
        }
        if (root->right) {
            rstr = postorder(root->right);
        }
        cstr = to_string(root->val) + " " + lstr + " " + rstr;
        if (++map[cstr] == 2) {
            res.push_back(root);
        }
        return cstr;
    }
};