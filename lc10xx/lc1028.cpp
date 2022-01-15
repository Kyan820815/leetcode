//--- Q: 1028. Recover a Tree From Preorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: stack iteration with recording depth
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode *> sk;
        int i = 0, val = 0, depth = 0;
        while (i <= traversal.size()) {
            if (i == traversal.size() || traversal[i] == '-') {
                auto now = new TreeNode(val);
                int right = 0;
                while (sk.size() > depth) {
                    right = 1;
                    sk.pop_back();
                }
                if (right) {
                    sk.back()->right = now;
                } else if (sk.size()) {
                    sk.back()->left = now;
                }
                sk.push_back(now);
                if (i == traversal.size()) {
                    break;
                }
                val = depth = 0;
                while (!isdigit(traversal[i])) {
                    ++depth, ++i;
                }
            } else {
                val = val*10 + (traversal[i++]-'0');
            }
        }
        return sk[0];
    }
};