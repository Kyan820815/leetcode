//--- Q: 0095. Unique Binary Search Trees II

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