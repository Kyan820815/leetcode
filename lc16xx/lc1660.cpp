//--- Q: 1660. Correct a Binary Tree

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

//--- method 1: bfs with map
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<TreeNode *> que;
        unordered_map<TreeNode *, TreeNode *> parent;
        que.push(root);
        while (que.size()) {
            int qsize = que.size();
            unordered_map<TreeNode *, TreeNode *> cur_parent;
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (now->left) {
                    cur_parent[now->left] = now;
                    que.push(now->left);
                }
                if (now->right) {
                    if (parent.find(now->right) != parent.end()) {
                        now->right = NULL;
                        auto p = parent[now];
                        if (p->left == now) {
                            p->left = NULL;
                        } else {
                            p->right = NULL;
                        }
                        return root;
                    }
                    cur_parent[now->right] = now;
                    que.push(now->right);
                }
            }
            parent = cur_parent;
        }
        return root;
    }
};