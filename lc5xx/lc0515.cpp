//--- Q: 515. Find Largest Value in Each Tree Row

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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return{};
    	queue<TreeNode *> que;
    	vector<int> res;
    	que.push(root);
    	int qsize = 1, maxval = INT_MIN;
    	while (que.size())
    	{
    		for (int i = 0; i < qsize; ++i)
    		{
    			TreeNode *now = que.front();
    			if (now->left)
    				que.push(now->left);
    			if (now->right)
    				que.push(now->right);
    			if (maxval < now->val)
    				maxval = now->val;
    			que.pop();
    		}
    		res.push_back(maxval);
    		maxval = INT_MIN;
    		qsize = que.size();
    	}
        return res;
    }
};

//--- method 2: dfs
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return{};
    	vector<int> res;
    	dfs(root, res, 0);
        return res;
    }
    void dfs(TreeNode *root, vector<int> &res, int h)
    {
    	if (h >= res.size())
    		res.push_back(root->val);
    	else
    		res[h] = max(res[h], root->val);
    	if (root->left)
    		dfs(root->left, res, h+1);
    	if (root->right)
    		dfs(root->right, res, h+1);
    }
};