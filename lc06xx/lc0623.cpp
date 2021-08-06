//--- Q: 0623. Add One Row to Tree

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        auto dummy = new TreeNode(-1, root, nullptr);
        return dfs(dummy, 0, depth, val)->left;
    }
    TreeNode *dfs(TreeNode *root, int cdepth, int depth, int val) {
        if (!root) {
            return nullptr;
        }
        if (cdepth+1 == depth) {
            auto nleft = new TreeNode(val);
            auto nright = new TreeNode(val);
            nleft->left = root->left;
            nright->right = root->right;
            root->left = nleft;
            root->right = nright;
        } else {
            root->left = dfs(root->left, cdepth+1, depth, val);
            root->right = dfs(root->right, cdepth+1, depth, val);
        }
        return root;
    }
};

//--- method 2: bfs
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        auto dummy = new TreeNode(-1, root, nullptr);
        queue<TreeNode *> que;
        que.push(dummy);
        int cdepth = 0;
        while (que.size() && cdepth < depth) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (cdepth+1 == depth)  {
                    auto nleft = new TreeNode(val);
                    auto nright = new TreeNode(val);
                    nleft->left = now->left;
                    nright->right = now->right;
                    now->left = nleft;
                    now->right = nright;
                } else {
                    if (now->left) {
                        que.push(now->left);
                    }
                    if (now->right) {
                        que.push(now->right);
                    }
                }
            }
            ++cdepth;
        }
        return dummy->left;
    }
};