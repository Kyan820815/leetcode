//--- Q: 0513. Find Bottom Left Tree Value

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs
class Solution {
public:
    int res;
    int findBottomLeftValue(TreeNode* root) {
        int maxh = -1;
        preorder(root, 0, maxh);
        return res;
    }
    void preorder(TreeNode *root, int h, int &maxh) {
        if (maxh < h) {
            maxh = h;
            res = root->val;
        }
        if (root->left) {
            preorder(root->left, h+1, maxh);
        }
        if (root->right) {
            preorder(root->right, h+1, maxh);
        }
    }
};

//--- method 2: bfs
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue<TreeNode *> que;
        que.push(root);
        while (que.size()) {
            auto qsize = que.size();
            res = que.front()->val;
            while (qsize--) {
                auto now = que.front();
                que.pop();
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
