//--- Q: 0958. Check Completeness of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bfs with clean code, better
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> que;
        que.push(root);
        while (1) {
            auto now = que.front();
            if (!now) {
                break;
            }
            que.pop();
            que.push(now->left);
            que.push(now->right);
        }
        while (que.size()) {
            auto now = que.front();
            que.pop();
            if (now) {
                return false;
            }
        }
        return true;
    }
};