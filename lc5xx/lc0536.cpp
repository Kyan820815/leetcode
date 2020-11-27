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
        if (s == "") {
            return NULL;
        }
        return dfs(idx, s);
    }
    TreeNode *dfs(int &idx, string &s) {
        int sum = 0, sign = 1;
        if (s[idx] == '-') {
            sign = -1;
            ++idx;
        }
        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
            sum = sum * 10 + s[idx++] - '0';
        }
        TreeNode *now = new TreeNode(sum * sign);
        if (s[idx] == '(') {
            now->left = dfs(++idx, s);
            ++idx;
        }
        if (s[idx] == '(') {
            now->right = dfs(++idx, s);
            ++idx;
        }
        return now;
    }
};