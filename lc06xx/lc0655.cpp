//--- Q: 0655. Print Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder with left and right handling
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> printTree(TreeNode* root) {
        int h = findh(root), sz = pow(2,h)-1;
        res.resize(h, vector<string>(sz));
        preorder(root, 0, 0, sz-1);
        return res;
    }
    void preorder(TreeNode *root, int h, int start, int end) {
        int mid = start + (end-start)/2;
        res[h][mid] = to_string(root->val);
        if (root->left) {
            preorder(root->left, h+1, start, mid-1);
        }
        if (root->right) {
            preorder(root->right, h+1, mid+1, end);
        }
    }
    int findh(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return max(findh(root->left), findh(root->right))+1;
    }
};