//--- Q: 958. Check Completeness of a Binary Tree

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
        while (que.size() && que.front()) {
            auto now = que.front();
            que.pop();
            que.push(now->left);
            que.push(now->right);
        }
        while (que.size() && !que.front()) {
            que.pop();
        }
        return !que.size();
    }
};

//--- method 2: bfs
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> que;
        int qsize = 1, last = 0;
        que.push(root);
        while (qsize) {
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (last && (now->left || now->right))
                    return false;
                if (now->left)
                    que.push(now->left);
                else if (now->right)
                    return false;
                if (now->right)
                    que.push(now->right);
                else
                    last = 1;
            }
            qsize = que.size();
        }
        return true;
    }
};