//--- Q: 872. Leaf-Similar Trees

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		string str1 = "", str2 = "";
		postorder(root1, str1);
		postorder(root2, str2);
		return str1 == str2;
    }
    void postorder(TreeNode *root, string &res)
    {
    	if (root->left)
    		postorder(root->left, res);
    	if (root->right)
    		postorder(root->right, res);
    	if (!root->left && !root->right)
    		res.push_back(root->val+'0');
    }
};