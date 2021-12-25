//--- Q: 0889. Construct Binary Tree from Preorder and Postorder Traversal

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

//--- method 1: dfs
class Solution {
public:
    int preidx = 0, postidx = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode *now = new TreeNode(preorder[preidx++]);
        if (now->val != postorder[postidx]) {
            now->left = constructFromPrePost(preorder, postorder);
        }
        if (now->val != postorder[postidx]) {
            now->right = constructFromPrePost(preorder, postorder);
        }
        ++postidx;
        return now;
    }
};

//--- method 2: stack iteration
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        vector<TreeNode *> sk;
        int preidx = 0, postidx = 0, n = preorder.size();
        while (preidx < n) {
            TreeNode *last = nullptr;
            while (sk.size() && sk.back()->val == postorder[postidx]) {
                last = sk.back();
                sk.pop_back();
                ++postidx;
            }
            auto now = new TreeNode(preorder[preidx++]);
            if (last) {
                sk.back()->right = now;
            } else if (sk.size()) {
                sk.back()->left = now;
            }
            sk.push_back(now);
        }
        return sk[0];
    }
};