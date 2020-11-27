//--- Q: 776. Split BST

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

class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode *> res(2, NULL);
        if (!root) {
            return  res;
        }
        if (root->val > V) {
            res = splitBST(root->left, V);
            root->left = res[1];
            res[1] = root;
        } else {
            res = splitBST(root->right, V);
            root->right = res[0];
            res[0] = root;
        }
        return res;
    }
};