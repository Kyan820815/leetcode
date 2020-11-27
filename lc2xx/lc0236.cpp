//--- Q: 236. Lowest Common Ancestor of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs without recording path
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
    TreeNode *dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
    	TreeNode *left = NULL, *right = NULL;
    	if (root == p || root == q || root == NULL)
    		return root;
    	left = dfs(root->left, p, q);
    	right = dfs(root->right, p, q);
    	if (left && right)
    		return root;
    	else if (!left && !right)
    		return NULL;
    	else if (!right)
    		return left;
    	else 
    		return right;
    }
};

//--- method 2: dfs with recording path
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<TreeNode*>> out_vec;
        vector<TreeNode*> out;
        int i;
        dfs(root, p, q, out_vec, out);
    	for (i = 0; i < out_vec[0].size() && i < out_vec[1].size(); ++i)
    	{
    		if (out_vec[0][i] == out_vec[1][i])
    			continue;
    		else
    			break;
    	}
    	return out_vec[0][i-1];
    }
    void dfs(TreeNode *root, TreeNode *p, TreeNode *q, vector<vector<TreeNode*>> &out_vec, vector<TreeNode*> &out)
    {
    	out.push_back(root);
    	if (root == p || root == q)
    		out_vec.push_back(out);
    	if (out_vec.size() == 2) return;

    	if (root->left)
    		dfs(root->left, p, q, out_vec, out);
    	if (root->right)
    		dfs(root->right, p, q, out_vec, out);
    	out.pop_back();
    	
    }
};