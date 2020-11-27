//--- Q: 1302. Deepest Leaves Sum

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

//--- method 1: dfs
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0, maxlevel = -1;
        dfs(root, res, 0, maxlevel);
        return res;
    }
    void dfs(TreeNode *root, int &res, int level, int &maxlevel) {
        if (level > maxlevel) {
            res = root->val;
            maxlevel = level;
        } else if (level == maxlevel) {
            res += root->val;
        }
        if (root->left) {
            dfs(root->left, res, level+1, maxlevel);
        }
        if (root->right) {
            dfs(root->right, res, level+1, maxlevel);
        }
    }
};

//--- method 2: bfs with queue
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res, i;
        queue<TreeNode *> que{{root}};
        while (que.size()) {
            int qsize = que.size();
            for (i = 0, res = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                res += now->val;
                if (now->left) {
                    que.push(now->left);
                }
                if (now->right) {
                    que.push(now->right);
                }
            }
        }
        return res;
    }
};