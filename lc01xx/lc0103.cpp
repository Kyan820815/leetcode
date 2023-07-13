//--- Q: 0103. Binary Tree Zigzag Level Order Traversal
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

//--- method 1: reverse vector without stl function
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> que;
        que.push(root);
        int dir = 1;
        while (que.size()) {
            auto qsize = que.size();
            int start = dir == 1 ? 0 : qsize-1;
            vector<int> tmp(qsize);
            while (qsize--) {
                auto now = que.front();
                que.pop();
                tmp[start] = now->val;
                if (now->left) {
                    que.push(now->left);
                }
                if (now->right) {
                    que.push(now->right);
                }
                start += dir;
            }
            dir *= -1;
            res.push_back(tmp);
        }
        return res;
    }
};