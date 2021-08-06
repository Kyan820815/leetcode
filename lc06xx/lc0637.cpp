//--- Q: 0637. Average of Levels in Binary Tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode *> que;
        que.push(root);
        while (que.size()) {
            auto qsize = que.size(), sz = qsize;
            double sum = 0;
            while (qsize--) {
                auto now = que.front();
                sum += now->val;
                que.pop();
                if (now->left) {
                    que.push(now->left);
                }
                if (now->right) {
                    que.push(now->right);
                }
            }
            res.push_back(sum/sz);
        }
        return res;
    }
};