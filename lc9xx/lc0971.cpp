//--- Q: 971. Flip Binary Tree To Match Preorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs with check left child val
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        int now = 0;
        preorder(root, voyage, res, now);
        return res;
    }
    void preorder(TreeNode *root, vector<int> &voyage, vector<int> &res, int &now)
    {
        if (!root)
        {
            --now;
            return;
        }
    	if (root->val != voyage[now])
    	{
    		res.clear();
    		res.push_back(-1);
    		return;
    	}
    	if (root->left)
    	{
    		if (root->left->val != voyage[++now])
            {
    			swap(root->left, root->right);
                res.push_back(root->val);                
            }
    		preorder(root->left, voyage, res, now);
    	}
    	if (root->right)
    		preorder(root->right, voyage, res, ++now);
    }
};