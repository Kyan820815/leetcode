//--- Q: 108. Convert Sorted Array to Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: find mid and recursively find mid of left &right
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	TreeNode *root = divide(nums, 0, nums.size()-1);
    	return root;
    }
    TreeNode *divide(vector<int> &nums, int start, int end)
    {
    	int mid;
    	TreeNode *node;
    	if (start <= end)
    	{
    		mid = (start+end)/2;
    		node = new TreeNode(nums[mid]);
    		node->left = divide(nums, start, mid-1);
    		node->right = divide(nums, mid+1, end);
    		return node;
    	}
    	return NULL;
    }
};

//--- 1-2: OTHER binary search
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = divide(nums, 0, nums.size()-1);
        return root;
    }
    TreeNode *divide(vector<int> &nums, int start, int end)
    {
        int mid;
        TreeNode *node;
        if (start > end) return NULL;
        if (start == end) return new TreeNode(nums[start]);
        if (start < end)
        {
            mid = (start+end)/2;
            node = new TreeNode(nums[mid]);
            node->left = divide(nums, start, mid-1);
            node->right = divide(nums, mid+1, end);
            return node;
        }
        return NULL;
    }
};