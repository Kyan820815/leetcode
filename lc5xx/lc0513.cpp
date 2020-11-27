//--- Q: 513. Find Bottom Left Tree Value

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bfs
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        return bfs(root);
    }
    int bfs(TreeNode *root)
    {
    	int first = root->val;
    	int qsize = 1;
    	queue<TreeNode *> que;
    	TreeNode *now;
    	que.push(root);
    	while(!que.empty())
    	{
    		now = que.front();
    		if (now->left)
    			que.push(now->left);
    		if (now->right)
    			que.push(now->right);
    		que.pop();
    		if (--qsize == 0)
    		{
    			qsize = que.size();
    			first = (!que.empty()) ? que.front()->val : first;
    		}
    	}
    	return first;
    }
};

//--- method 2: dfs
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
    	int first, maxh = -1, height = 0;
    	dfs(root, height, maxh, first);
    	return first;
    }
    void dfs(TreeNode *root, int height, int &maxh, int &first)
    {
    	if (height > maxh)
    	{
    		first = root->val;
    		maxh = height;
    	}
    	if (root->left)
    		dfs(root->left, height+1, maxh, first);
    	if (root->right)
    		dfs(root->right, height+1, maxh, first);
    }
};