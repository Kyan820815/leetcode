//--- Q: 654. Maximum Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: beautiful code using descendent order vector
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	vector<TreeNode*> vec;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		TreeNode *cur = new TreeNode(nums[i]);
    		while (vec.size() != 0 && vec.back()->val < nums[i])
    		{
    			cur->left = vec.back();
    			vec.pop_back();
    		}
    		if (vec.size() != 0)
    			vec.back()->right = cur;
    		vec.push_back(cur);
    	}
    	return vec.front();
    }
};

//--- method 2: dfs recursion
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return make_tree(nums, 0, nums.size()-1);
    }
    TreeNode *make_tree(vector<int> &nums, int left, int right)
    {
    	if (left > right) return NULL;
    	int max = INT_MIN, max_idx;
    	for (int i = left; i <= right; ++i)
    	{
    		if (nums[i] > max)
    		{
    			max = nums[i];
    			max_idx = i;
    		}
    	}
    	TreeNode *root = new TreeNode(max);
    	root->left = make_tree(nums, left, max_idx-1);
    	root->right = make_tree(nums, max_idx+1, right);
    	return root;
    }
};

