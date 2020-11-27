//--- Q: 095. Unique Binary Search Trees II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion (dp)
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> root_vec;
        if (!n) return vector<TreeNode *>{};
        dfs(1, n, root_vec);
        return root_vec;
    }

    void dfs(int start, int end, vector<TreeNode *> &out_vec)
    {
    	TreeNode *node;
    	vector<TreeNode *> left_node;
    	vector<TreeNode *> right_node;

    	if (start > end)
    	{
    		out_vec.push_back(NULL);
    		return;
    	}
    	
		for (int i = start; i <= end; ++i)
    	{
    		left_node.clear();
    		right_node.clear();
    		dfs(start, i-1, left_node);
    		dfs(i+1, end, right_node);

    		for (int j = 0; j < left_node.size(); ++j)
    		{
    			for (int k = 0; k < right_node.size(); ++k)
    			{
    				node = new TreeNode(i);
    				node->left = left_node[j];
    				node->right = right_node[k];
    				out_vec.push_back(node);
    			}
    		}

    	}
    }
};