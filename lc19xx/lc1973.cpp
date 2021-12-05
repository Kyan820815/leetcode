//--- Q: 1973. Count Nodes Equal to Sum of Descendants

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

//--- method 1: postorder recursion
class Solution {
public:
    int res = 0;
    using ll = long long;
    int equalToDescendants(TreeNode* root) {
        postorder(root);
        return res;
    }
    ll postorder(TreeNode *root) {
        ll lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left);
        }
        if (root->right) {
            rv = postorder(root->right);
        }
        res += root->val == lv+rv;
        return lv+rv+root->val;
    }
};