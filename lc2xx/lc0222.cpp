//--- Q: 222. Count Complete Tree Nodes

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs with counting complete tree
class Solution {
public:
    int countNodes(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode *root)
    {
    	TreeNode *left_node, *right_node;
    	left_node = root;
    	right_node = root;
    	int l_c = 0, r_c = 0;

    	while(left_node)
    	{
    		left_node = left_node->left;
    		l_c++;
    	}
    	while(right_node)
    	{
    		right_node = right_node->right;
    		r_c++;
    	}
        if (!l_c)
            return 0;
    	else if (l_c == r_c)
            return (1<<l_c) - 1;
    	else
            return 1+dfs(root->left)+dfs(root->right);
    }
};

//--- method 2: general dfs
class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        if (!root) return count;
        dfs(root, count);
        return count;
    }
    void dfs(TreeNode *root, int &count)
    {
    	count++;
    	if (root->left)
    		dfs(root->left, count);
    	if (root->right)
    		dfs(root->right, count);
    }
};