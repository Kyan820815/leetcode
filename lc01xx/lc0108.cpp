//--- Q: 0108. Convert Sorted Array to Binary Search Tree
//--- last written: 2023/07/13

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
        return dfs(0, nums.size()-1, nums);
    }
    TreeNode *dfs(int start, int end, vector<int> &nums) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end-start)/2;
        auto now = new TreeNode(nums[mid]);
        now->left = dfs(start, mid-1, nums);
        now->right = dfs(mid+1, end, nums);
        return now;
    }
};