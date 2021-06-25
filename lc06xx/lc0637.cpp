//--- Q: 637. Average of Levels in Binary Tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<int> size;
        if (!root) return {};
        preorder(root, res, h);
        for (int i = 0; i < res.size(); ++i)
        	res[i] /= size[i];
        return res;
    }
    void preorder(TreeNode *root, vector<double> &res, vector<int> &size, int h)
    {
    	if (res.size() == h)
    	{
    		res.push_back(root->val);
    		size.push_back(1);
    	}
    	else
    	{
    		res[h] += root->val;
    		++size[h];
    	}
    	if (root->left)
    		preorder(root->left, res, h+1);
    	if (root->right)
    		preorder(root->right, res, h+1);
    }
};

//--- method 2: bfs
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> que;
        vector<double> res;
        int n = 1;
        if (!root) return {};
        que.push(root);
        while (que.size())
        {
        	double sum = 0;
        	for (int i = 0; i < n; ++i)
        	{
        		TreeNode *now = que.front();
        		que.pop();
        		if (now->left)
        			que.push(now->left);
        		if (now->right)
        			que.push(now->right);
        		sum += now->val;
        	}
        	res.push_back(sum/n);
        	n = que.size();
        }
        return res;
    }
};