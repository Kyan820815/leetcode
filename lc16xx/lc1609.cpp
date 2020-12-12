//--- Q: 1609. Even Odd Tree

//--- method 1: bfs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int sign = 1;
        queue<TreeNode *> que;
        que.push(root);
        while (que.size()) {
            int qsize = que.size();
            int val = sign ? 0 : 1000001;
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                if ((now->val&1) != sign || sign && val >= now->val || !sign && val <= now->val) {
                    return false;
                }
                que.pop();
                if (now->left) {
                    que.push(now->left);
                }
                if (now->right) {
                    que.push(now->right);
                }
                val = now->val;
            }
            sign ^= 1;
        }
        return true;
    }
};