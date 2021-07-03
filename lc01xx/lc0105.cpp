//--- Q: 0105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return dfs(idx, 0, inorder.size()-1, preorder, inorder);
    }
    TreeNode *dfs(int &idx, int start, int end, vector<int>& preorder, vector<int>& inorder) {
        if (start > end) {
            return NULL;
        }
        int mid;
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == preorder[idx]) {
                mid = i;
                break;
            }
        }
        auto now = new TreeNode(preorder[idx++]);
        now->left = dfs(idx, start, mid-1, preorder, inorder);
        now->right = dfs(idx, mid+1, end, preorder, inorder);
        return now;
    }
};

//--- method 2: iteration
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *last = NULL, *root = NULL;
        vector<TreeNode *> sk;
        for (int i = 0, j = 0; i < preorder.size();) {
            if (sk.size() && sk.back()->val == inorder[j]) {
                last = sk.back();
                sk.pop_back();
                ++j;
            } else if (last) {
                auto now = new TreeNode(preorder[i++]);
                last->right = now;
                sk.push_back(now);
                last = NULL;
            } else {
                auto now = new TreeNode(preorder[i++]);
                if (sk.size()) {
                    sk.back()->left = now;
                } else if (!root) {
                    root = now;
                }
                sk.push_back(now);
            }
        }
        return root;
    }
};
