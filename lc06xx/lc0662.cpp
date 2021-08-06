//--- Q: 0662. Maximum Width of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bfs
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,int>> que;
        que.push({root,0});
        int res = 0;
        while (que.size()) {
            res = max(res, que.back().second-que.front().second+1);
            auto qsize = que.size();
            auto diff = que.front().second;
            while (qsize--) {
                auto now = que.front();
                auto val = now.second-diff;
                que.pop();
                if (now.first->left) {
                    que.push({now.first->left, val*2});
                }
                if (now.first->right) {
                    que.push({now.first->right, val*2+1});
                }
            }
        }
        return res;
    }
};