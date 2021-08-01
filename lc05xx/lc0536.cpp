//--- Q: 0536. Construct Binary Tree from String

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
        if (!s.size()) {
            return nullptr;
        }
        int idx = 0;
        return dfs(idx, s);
    }
    TreeNode *dfs(int &idx, string &s) {
        int val = 0, sign = 1;
        if (s[idx] == '-') {
            sign = -1;
            ++idx;
        }
        for (; idx < s.size() && isdigit(s[idx]); ++idx) {
            val = val * 10 + (s[idx]-'0');
        }
        auto now = new TreeNode(val*sign);
        if (idx < s.size() && s[idx] == '(') {
             ++idx;
            now->left = dfs(idx, s);
            ++idx;
        }
        if (idx < s.size() && s[idx] == '(') {
            ++idx;
            now->right = dfs(idx, s);
            ++idx;
        }
        return now;
    }
};

//--- method 2: stack
class Solution {
public:
    TreeNode* str2tree(string s) {
        vector<TreeNode *> sk;
        int val, sign, lv = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == '(') {
                ++i;
            } else if (s[i] == ')') {
                ++i;
                sk.pop_back();
            } else {
                sign = 1, val = 0;
                if (s[i] == '-') {
                    sign = -1;
                    ++i;
                }
                for (; i < s.size() && isdigit(s[i]); ++i) {
                    val = val * 10 + (s[i]-'0');
                }
                auto now = new TreeNode(val*sign);
                if (sk.size()) {
                    if (sk.back()->left) {
                        sk.back()->right = now;
                    } else {
                        sk.back()->left = now;
                    }
                }
                sk.push_back(now);
            }
        }
        return sk.size() ? sk[0] : nullptr;
    }
};