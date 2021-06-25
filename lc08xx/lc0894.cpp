//--- Q: 894. All Possible Full Binary Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion, slow
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        return dfs(0, N-1);
    }
    vector<TreeNode *> dfs(int left, int right)
    {
    	vector<TreeNode *> res;
    	if (left > right)
    		return vector<TreeNode *>{NULL};
    	else if (left == right)
    		return vector<TreeNode *>{new TreeNode(0)};

    	for (int i = left+1; i <= right-1; ++i)
    	{
    		vector<TreeNode *> left_tree = dfs(left, i-1);
    		vector<TreeNode *> right_tree = dfs(i+1, right);

    		for (int j = 0; j < left_tree.size(); ++j)
    		{
    			for (int k = 0; k < right_tree.size(); ++k)
    			{
		    		TreeNode *root = new TreeNode(0);
    				root->left = left_tree[j];
    				root->right = right_tree[k];
    				res.push_back(root);
    			}
    		}
    	}
    	return res;
    }
};

//--- method 2: faster solution (better)
class Solution {
public:
	unordered_map<int, vector<TreeNode *>> map;
    vector<TreeNode*> allPossibleFBT(int N) {
        return dfs(0, N-1);
    }
    vector<TreeNode *>dfs(int left, int right)
    {
    	vector<TreeNode *> res;
    	if (left > right)
    		return vector<TreeNode *>{NULL};
    	else if (left == right)
    		return vector<TreeNode *>{new TreeNode(0)};

    	for (int i = left+1; i <= (left+right)/2; i += 2)
    	{
    		vector<TreeNode *> left_tree = dfs(left, i-1);
    		vector<TreeNode *> right_tree = dfs(i+1, right);

    		for (int j = 0; j < left_tree.size(); ++j)
    		{
    			for (int k = 0; k < right_tree.size(); ++k)
    			{
		    		TreeNode *root = new TreeNode(0);
    				root->left = left_tree[j];
    				root->right = right_tree[k];
    				res.push_back(root);
    				
    				if (i == (left+right) / 2)
    					continue;
    				
    				root = new TreeNode(0);
    				root->left = right_tree[k];
    				root->right = left_tree[j];
    				res.push_back(root);
    			}
    		}
    	}
    	return res;
    }
};