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
        int res = INT_MIN, level = 1, maxlevel;
        que.push(root);
        while (que.size()) {
            auto qsize = que.size();
            int sum = 0;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                sum += now->val;
                if (now->left) {
                    que.push(now->left);
                }
                if (now->right) {
                    que.push(now->right);
                }
            }
            if (sum > res) {
                res = sum;
                maxlevel = level;
            }
            ++level;
        }
        return maxlevel;
    }
};