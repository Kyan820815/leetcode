//--- Q: 1161. Maximum Level Sum of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bfs, queue
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> que;
        que.push(root);
        int qsize = 1, maxv = INT_MIN, level = 0, maxl;
        while (qsize) {
            int nowv = 0;
            ++level;
            for (auto i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                nowv += now->val;
                if (now->left)
                    que.push(now->left);
                if (now->right)
                    que.push(now->right);
            }
            if (maxv < nowv) {
                maxv = nowv;
                maxl = level;
            }
            qsize = que.size();
        }
        return maxl;
    }
};