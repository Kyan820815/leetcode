//--- Q: 623. Add One Row to Tree

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
    	if (d == 1)
    	{
    		TreeNode *dummy = new TreeNode(v);
    		dummy->left = root;
    		return dummy;
    	}
		dfs(root, 1, d, v);
		return root;       
    }
    void dfs(TreeNode *root, int height, int d, int v)
    {
    	TreeNode *left_tree, *right_tree;
    	if (height == d-1)
    	{
    		left_tree = root->left;
    		right_tree = root->right;
    		root->left = new TreeNode(v);
    		root->right = new TreeNode(v);
    		root->left->left = left_tree;
    		root->right->right = right_tree;
    		return;
    	}
    	if (root->left)
    		dfs(root->left, height+1, d, v);
    	if (root->right)
    		dfs(root->right, height+1, d, v);
    }
};

//--- method 2: bfs
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
    	if (d == 1)
    	{
    		TreeNode *dummy = new TreeNode(v);
    		dummy->left = root;
    		return dummy;
    	}
    	int level = 1, q_size = 1;
    	queue<TreeNode *> que;
    	TreeNode *left_tree, *right_tree, *now;
    	que.push(root);
    	while (que.size() > 0)
    	{
    		if (level == d-1)
    		{
    			while(que.size() > 0)
    			{
    				now = que.front();
    				que.pop();
    				left_tree = now->left;
    				right_tree = now->right;
    				now->left = new TreeNode(v);
    				now->right = new TreeNode(v);
    				now->left->left = left_tree;
    				now->right->right = right_tree;
    			}
    			break;
    		}
    		now = que.front();
    		que.pop();
    		if (now->left)
    			que.push(now->left);
    		if (now->right)
    			que.push(now->right);

    		--q_size;
    		if (q_size == 0)
    		{
    			q_size = que.size();
    			++level;
    		}
    	}
		return root;       
    }
};