//--- Q: 0654. Maximum Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(0, nums.size()-1, nums);
    }
    TreeNode *dfs(int start, int end, vector<int> &nums) {
        if (start > end) {
            return nullptr;
        }
        int maxv = INT_MIN, maxi;
        for (int i = start; i <= end; ++i) {
            if (nums[i] > maxv) {
                maxv = nums[i];
                maxi = i;
            }
        }
        TreeNode *now = new TreeNode(maxv);
        now->left = dfs(start, maxi-1, nums);
        now->right = dfs(maxi+1, end, nums);
        return now;
    }
};

//--- method 2: beautiful code using descendent order vector
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode *> sk;
        for (int i = 0; i < nums.size(); ++i) {
            TreeNode *now = new TreeNode(nums[i]), *last = nullptr;
            while (sk.size() && sk.back()->val < nums[i]) {
                last = sk.back();
                sk.pop_back();
            }
            now->left = last;
            if (sk.size()) {
                sk.back()->right = now; 
            }
            sk.push_back(now);
        }
        return sk[0];
    }
};