//--- Q: 199. Binary Tree Right Side View

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
    vector<int> rightSideView(TreeNode* root) {
    	int q_size;
		queue<TreeNode *> que;
		vector<int> ans;
		TreeNode *now;
		if (!root) return vector<int>{};
		que.push(root);
		q_size = 1;

		while(que.size() != 0)
		{
			now = que.front();
			que.pop();
			if (now->left)
				que.push(now->left);
			if (now->right)
				que.push(now->right);
			q_size--;
			if (q_size == 0)
			{
				q_size = que.size();
				ans.push_back(now->val);
			}
		}
	    return ans;
    }
};

//--- method 2: dfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> ans;
    	int max = INT_MIN;
    	if (!root) return ans;
    	dfs(root, 0, max, ans);
    	return ans;
    }
    void dfs(TreeNode *root, int level, int &max, vector<int> &ans)
    {
    	if (level > max)
    	{
    		max = level;
			ans.push_back(root->val);    		
    	}
    	if (root->right)
    		dfs(root->right, level+1, max, ans);
    	if (root->left)
    		dfs(root->left, level+1, max, ans);
    }
};