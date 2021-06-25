//--- Q: 662. Maximum Width of Binary Tree

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
        int res = 0;
        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        while (que.size()) {
            int hv = que.front().second, qsize = que.size();
            res = max(res, que.back().second-que.front().second+1);
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (now.first->left) {
                    que.push({now.first->left, (now.second-hv)*2});
                }
                if (now.first->right) {
                    que.push({now.first->right, (now.second-hv)*2+1});
                }
            }
        }
        return res;
    }
};