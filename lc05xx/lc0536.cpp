//--- Q: 536. Construct Binary Tree from String

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

//--- method 1: dfs recursion
class Solution {
public:
    TreeNode* str2tree(string s) {
        int idx = 0;
        return dfs(idx, s);
    }
    TreeNode *dfs(int &idx, string &s) {
        if (idx >= s.size()) {
            return NULL;
        }
        int val, now = idx;
        while (now < s.size() && s[now] != '(' && s[now] != ')') {
            ++now;
        }
        val = stoi(s.substr(idx, now-idx));
        TreeNode *node = new TreeNode(val);
        idx = now;
        if (s[idx] == '(') {
            ++idx;
            node->left = dfs(idx, s);
        }
        if (s[idx] == '(') {
            ++idx;
            node->right = dfs(idx, s);
        }
        ++idx;
        return node;
    }
};