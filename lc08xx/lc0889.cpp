//--- Q: 889. Construct Binary Tree from Preorder and Postorder Traversal

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
    int pre_idx = 0, post_idx = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode *root = new TreeNode(pre[pre_idx++]);
        if (root->val != post[post_idx]) {
            root->left = constructFromPrePost(pre, post);
        }
        if (root->val != post[post_idx]) {
            root->right = constructFromPrePost(pre, post);
        }
        ++post_idx;
        return root;
    }
};

//--- method 2: stack iteration
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode *> tree;
        tree.push_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); ++i) {
            TreeNode *now = new TreeNode(pre[i]);
            while (tree.back()->val == post[j]) {
                ++j;
                tree.pop_back();
            }
            if (!tree.back()->left) {
                tree.back()->left = now;
            } else {
                tree.back()->right = now;
            }
            tree.push_back(now);
        }
        return tree[0];
    }
};