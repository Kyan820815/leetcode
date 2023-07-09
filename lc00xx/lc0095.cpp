//--- Q: 0095. Unique Binary Search Trees II
//--- last written: 2023/07/09

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion (dp)
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return preorder(1, n);
    }
    vector<TreeNode *> preorder(int start, int end) {
        if (start > end) {
            return {NULL};
        } else if (start == end) {
            return {new TreeNode(start)};
        }
        vector<TreeNode *> res;
        for (int i = start; i <= end; ++i) {
            auto left_vec = preorder(start, i-1);
            auto right_vec = preorder(i+1, end);
            for (auto &left_node: left_vec) {
                for (auto &right_node: right_vec) {
                    auto now = new TreeNode(i);
                    now->left = left_node;
                    now->right = right_node;
                    res.push_back(now);
                }
            }
        }
        return res;
    }
};

//--- method 2: dp iteration
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode *>> res(n+1);
        res[0] = {NULL};
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (auto &left_node: res[j]) {
                    for (auto &right_node: res[i-j-1]) {
                        auto now = new TreeNode(j+1);
                        now->left = left_node;
                        now->right = clone(right_node, j+1);
                        res[i].push_back(now);
                    }
                }
            }
        }
        return res.back();
    }
    TreeNode *clone(TreeNode *node, int offset) {
        if (!node) {
            return node;
        }
        auto new_node = new TreeNode(node->val+offset);
        new_node->left = clone(node->left, offset);
        new_node->right = clone(node->right, offset);
        return new_node;
    }
};
