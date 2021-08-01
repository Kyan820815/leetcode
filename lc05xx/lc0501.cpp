//--- Q: 0501. Find Mode in Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: track last node cnt
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        TreeNode *last = nullptr;
        int maxcnt = 0, cnt = 0;
        while (root) {
            if (root->left) {
                auto prev = root;
                root = root->left;
                while (root->right && root->right != prev) {
                    root = root->right;
                }
                if (root->right) {
                    if (last && last->val != prev->val) {
                        if (cnt > maxcnt) {
                            res = {last->val};
                            maxcnt = cnt;
                        } else if (cnt == maxcnt) {
                            res.push_back(last->val);
                        }
                        cnt = 0;
                    }
                    ++cnt;
                    root->right = nullptr;
                    last = prev;
                    root = prev->right;
                } else {
                    root->right = prev;
                    root = prev->left;
                }
            } else {
                if (last && last->val != root->val) {
                    if (cnt > maxcnt) {
                        res = {last->val};
                        maxcnt = cnt;
                    } else if (cnt == maxcnt) {
                        res.push_back(last->val);
                    }
                    cnt = 0;
                }
                ++cnt;
                last = root;
                root = root->right;
            }
        }
        if (cnt > maxcnt) {
            res = {last->val};
        } else if (cnt == maxcnt) {
            res.push_back(last->val);
        }
        return res;
    }
};