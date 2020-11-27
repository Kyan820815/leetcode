//--- Q: 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target) {
            return cloned;
        }
        TreeNode *lv = NULL, *rv = NULL;
        if (original->left) {
            lv = getTargetCopy(original->left, cloned->left, target);
        }
        if (original->right) {
            rv = getTargetCopy(original->right, cloned->right, target);
        }
        return lv ? lv : rv;
    }
};