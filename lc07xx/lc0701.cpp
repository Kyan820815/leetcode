//--- Q: 701. Insert into a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode (val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};

//--- method 2: iteration, O(1) space
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        int dir = 0;
        TreeNode *dummy = new TreeNode(-1), *now = root, *p = dummy;
        dummy->left = root;
        while (now) {
            p = now;
            if (now->val < val) {
                dir = 1;
                now = now->right;
            } else {
                dir = 0;
                now = now->left;
            }
        }
        if (dir) {
            p->right = new TreeNode(val);
        } else {
            p->left = new TreeNode(val);
        }
        return dummy->left;
    }
};