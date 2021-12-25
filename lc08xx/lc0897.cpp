//--- Q: 0897. Increasing Order Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inroder iteration stack
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *now = root, *dummy = new TreeNode(-1), *last = dummy;
        vector<TreeNode *> sk;
        while (now || sk.size()) {
            while (now) {
                sk.push_back(now);
                now = now->left;
            }
            now = sk.back();
            sk.pop_back();
            now->left = nullptr;
            last->right = now;
            last = now;
            now = now->right;
        }
        return dummy->right;
    }
};

//--- method 2: O(1) traversal
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *now = root, *dummy = new TreeNode(-1, nullptr, root), *last = dummy;
        while (now) {
            if (now->left) {
                auto prev = now;
                now = now->left;
                while (now->right) {
                    now = now->right;
                }
                now->right = prev;
                now = prev->left;
                prev->left = nullptr;
                last->right = now;
            } else {
                last = now;
                now = now->right;
            }
        }
        return dummy->right;
    }
};