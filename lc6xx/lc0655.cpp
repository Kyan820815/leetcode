//--- Q: 655. Print Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder with left and right handling
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = findHeight(root);
        int width = (1 << height) - 1;
        vector<vector<string>> res(height, vector<string>(width, ""));
        preorder(root, 0, 0, width-1, res);
        return res;
        
    }
    void preorder(TreeNode *root, int h, int l, int r, vector<vector<string>> &res) {
        int mid = (l+r) >> 1;
        res[h][mid] = to_string(root->val);
        if (root->left) {
            preorder(root->left, h+1, l, mid-1, res);
        }
        if (root->right) {
            preorder(root->right, h+1, mid+1, r, res);
        }
    }
    int findHeight(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int lv = findHeight(root->left);
        int rv = findHeight(root->right);
        return max(lv, rv) + 1;
    }
};