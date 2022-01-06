//--- Q: 0971. Flip Binary Tree To Match Preorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs with check left child val
class Solution {
public:
    vector<int> res;
    int idx = 0, find = 1;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        preorder(root, voyage);
        return !find ? vector<int>{-1} : res;
    }
    void preorder(TreeNode *root, vector<int> &voyage) {
        if (!root) {
            return;
        }
        if (root->val != voyage[idx]) {
            find = 0;
            return;
        }
        ++idx;
        if (root->left) {
            if (root->left->val == voyage[idx]) {
                preorder(root->left, voyage);
                preorder(root->right, voyage);
            } else {
                res.push_back(root->val);
                preorder(root->right, voyage);
                preorder(root->left, voyage);
            }
        } else {
            preorder(root->right, voyage);
        }
    }
};