//--- Q: 1602. Find Nearest Right Node in Binary Tree

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

//--- method 1: bfs
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode *> que;
        que.push(root);
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (now == u) {
                    return i == qsize-1 ? NULL : que.front();
                }
                if (now->left) {
                    que.push(now->left);
                }
                if (now->right) {
                    que.push(now->right);
                }
            }
        }
        return NULL;
    }
};

//--- method 2: morris
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        TreeNode *now = root, *res = NULL;
        int depth = 0, target_depth = -1;
        while (now) {
            if (now->left) {
                TreeNode *pre = now;
                now = now->left;
                int delta = 1;
                while (now->right && now->right != pre) {
                    now = now->right;
                    ++delta;
                }
                if (now->right == pre) {
                    now->right = NULL;
                    now = pre->right;
                    depth -= delta;
                } else {
                    now->right = pre;
                    if (pre == u) {
                        target_depth = depth;
                    } else if (!res && depth == target_depth) {
                        res = pre;
                    }
                    now = pre->left;
                    depth++;
                }
            } else {
                if (now == u) {
                    target_depth = depth;
                } else if (!res && depth == target_depth) {
                    res = now;
                }
                depth++;
                now = now->right;
            }
        }
        return res;
    }
};