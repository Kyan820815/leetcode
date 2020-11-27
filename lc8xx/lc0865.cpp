//--- Q: 865. Smallest Subtree with all the Deepest Nodes

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    	int depth = 0;
        return postorder(root, depth);
    }
    TreeNode *postorder(TreeNode *root, int &depth)
    {
    	int ldepth = 0, rdepth = 0;
    	TreeNode *lnode = NULL, *rnode = NULL;
    	if (root->left)
    		lnode = postorder(root->left, ldepth);
    	if (root->right)
    		rnode = postorder(root->right, rdepth);
    	if (ldepth > rdepth)
    	{
    		depth = ldepth+1;
    		return lnode;
    	}
    	else if (rdepth > ldepth)
    	{
    		depth = rdepth+1;
    		return rnode;
    	}
    	else
    	{
    		depth = rdepth+1;
    		return root;
    	}
    }
};