//--- Q: 156. Binary Tree Upside Down

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder without last pointer
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode *nr = NULL;
        postorder(root, &nr);
        return nr;
    }
    void postorder(TreeNode *root, TreeNode **nr) {
        if (root->left)
            postorder(root->left, nr);
        if (root->right)
            postorder(root->right, nr);
        
        if (*nr == NULL)
            *nr = root;
        
        if (root->left) {
            root->left->right = root;
            root->left->left = root->right;            
        }
        root->left = NULL;
        root->right = NULL;
    }
};

