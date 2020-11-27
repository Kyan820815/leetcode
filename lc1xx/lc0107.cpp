//--- Q: Binary Tree Level Order Traversal II

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level_val;
        queue<TreeNode *> que;
        if (!root) return {};
        int qsize = 1;
        que.push(root);
        while (que.size())
        {
        	TreeNode *now = que.front();
        	if (now->left)
        		que.push(now->left);
        	if (now->right)
        		que.push(now->right);
        	que.pop();
        	level_val.push_back(now->val);
        	--qsize;
        	if (qsize == 0)
        	{
        		qsize = que.size();
        		res.insert(res.begin(), level_val);
        		level_val.resize(0);
        	}
        }
        return res;
    }
};

//--- method 2: dfs
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
		vector<vector<int>> res;
        dfs(res, root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(vector<vector<int>> &res, TreeNode *root, int level)
    {
    	if (level == res.size())
    		res.push_back({root->val});
    	else
    		res[level].push_back(root->val);
    	if (root->left)
    		dfs(res, root->left, level+1);
    	if (root->right)
    		dfs(res, root->right, level+1);
    }
};