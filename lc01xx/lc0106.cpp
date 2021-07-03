//--- Q: 0106. Construct Binary Tree from Inorder and Postorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: recursion
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        return dfs(idx, 0, inorder.size()-1, inorder, postorder);
    }
    TreeNode *dfs(int &idx, int start, int end, vector<int>& inorder, vector<int>& postorder) {
        if (start > end) {
            return NULL;
        }
        int mid;
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == postorder[idx]) {
                mid = i;
                break;
            }
        }
        auto now = new TreeNode(postorder[idx--]);
        now->right = dfs(idx, mid+1, end, inorder, postorder);
        now->left = dfs(idx, start, mid-1, inorder, postorder);
        return now;
    }
};

//--- method 2: iteration
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *last = NULL, *root = NULL;
        vector<TreeNode *> sk;
        for (int i = postorder.size()-1, j = inorder.size()-1; i >= 0;) {
            if (sk.size() && sk.back()->val == inorder[j]) {
                last = sk.back();
                sk.pop_back();
                --j;
            } else if (last) {
                auto now = new TreeNode(postorder[i--]);
                last->left = now;
                sk.push_back(now);
                last = NULL;
            } else {
                auto now = new TreeNode(postorder[i--]);
                if (sk.size()) {
                    sk.back()->right = now;
                } else if (!root) {
                    root = now;
                }
                sk.push_back(now);
            }
        }
        return root;
    }
};