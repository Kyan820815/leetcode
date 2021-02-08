//--- Q: 1382. Balance a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//--- method 1: inorder + postorder
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return dfs(0, res.size()-1, res);
    }
    TreeNode *dfs(int left, int right, vector<int> &res) {
        if (left > right) {
            return NULL;
        }
        int mid = left + (right-left)/2;
        TreeNode *now = new TreeNode(res[mid]);
        now->left = dfs(left, mid-1, res);
        now->right = dfs(mid+1, right, res);
        return now;
    }
    void inorder(TreeNode *root, vector<int> &res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};