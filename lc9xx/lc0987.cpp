//--- Q: 987. Vertical Order Traversal of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs (preorder) with hashmap
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    	vector<vector<int>> res;
    	map<int, map<int, set<int>>> info;
    	preorder(root, info, 0, 0);
    	for (auto &in: info)
    	{
    		vector<int> res_vec;
    		for (auto &ii: in.second)
    			res_vec.insert(res_vec.end(), ii.second.begin(), ii.second.end());
    		res.push_back(res_vec);
    	}
    	return res;
    }
    void preorder(TreeNode *root, map<int, map<int, set<int>>> &info, int x, int y)
    {
    	info[x][y].insert(root->val);
    	if (root->left)
    		preorder(root->left, info, x-1, y+1);
    	if (root->right)
    		preorder(root->right, info, x+1, y+1);
    }
};

//--- method 2: bfs with hashmap
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        int qsize = 1;
        queue<pair<TreeNode *,pair<int,int>>> que;
        map<int, map<int, set<int>>> info;
        que.push({root,{0,0}});
        while (que.size())
        {
        	for (int i = 0; i < qsize; ++i)
        	{
        		pair<TreeNode *, pair<int,int>> now = que.front();
        		que.pop();
        		int x = now.second.first, y = now.second.second;
        		info[x][y].insert(now.first->val);
        		if (now.first->left)
        			que.push({now.first->left, {x-1,y+1}});
        		if (now.first->right)
        			que.push({now.first->right, {x+1,y+1}});
        	}
        	qsize = que.size();
        }
        for (auto &in: info)
        {
        	vector<int> res_vec;
        	for (auto &ii: in.second)
        		res_vec.insert(res_vec.end(), ii.second.begin(), ii.second.end());
        	res.push_back(res_vec);
        }
        return res;
    }
};