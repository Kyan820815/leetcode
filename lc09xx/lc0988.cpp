//--- Q: 988. Smallest String Starting From Leaf

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
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
    	string res = "";
    	preorder(root, res, "");
    	return res;
    }
    void preorder(TreeNode *root, string &res, string now)
    {
    	now.push_back(root->val+'a');
    	if (!root->left && !root->right)
    	{
    		reverse(now.begin(), now.end());
    		if (!res.size())
    			res = now;
    		else
    			res = min(res, now);
    	}
    	if (root->left)
    		preorder(root->left, res, now);
    	if (root->right)
    		preorder(root->right, res, now);
    }
};