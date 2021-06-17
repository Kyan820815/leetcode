//--- Q: 501. Find Mode in Binary Search Tree

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
        TreeNode *last = NULL;
        int maxv = 0, cnt = 0;
        while (root) {
            if (root->left) {
                auto prev = root;
                root = root->left;
                while (root->right && root->right != prev) {
                    root = root->right;
                }
                if (!root->right) {
                    root->right = prev;
                    root = prev->left;
                } else {
                    if (last && last->val != prev->val) {
                        if (cnt > maxv) {
                            maxv = cnt;
                            res = {last->val};
                        } else if (cnt == maxv) {
                            res.push_back(last->val);
                        }
                        cnt = 0;
                    }
                    ++cnt;
                    last = prev;
                    root->right = NULL;
                    root = prev->right;
                }
            } else {
                if (last && last->val != root->val) {
                    if (cnt > maxv) {
                        maxv = cnt;
                        res = {last->val};
                    } else if (cnt == maxv) {
                        res.push_back(last->val);
                    }
                    cnt = 0;
                }
                ++cnt;
                last = root;
                root = root->right;
            }
        }
        if (cnt > maxv) {
            maxv = cnt;
            res = {last->val};
        } else if (cnt == maxv) {
            res.push_back(last->val);
        }
        return res;
    }
};