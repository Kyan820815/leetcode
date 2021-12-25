//--- Q: 0872. Leaf-Similar Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string str1 = "", str2 = "";
        preorder(root1, str1);
        preorder(root2, str2);
        return str1 == str2;
    }
    void preorder(TreeNode *root, string &str) {
        if (!root->left && !root->right) {
            str += (root->val+'0');
        }
        if (root->left) {
            preorder(root->left, str);
        }
        if (root->right) {
            preorder(root->right, str);
        }
    }
};