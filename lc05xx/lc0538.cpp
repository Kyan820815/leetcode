//--- Q: 0538. 0Convert BST to Greater Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 3: morris traversal
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        auto now = root;
        int sum = 0;
        while (now) {
            if (now->right) {
                auto prev = now;
                now = now->right;
                while (now->left && now->left != prev) {
                    now = now->left;
                }
                if (now->left) {
                    prev->val += sum;
                    sum = prev->val;
                    now->left = nullptr;
                    now = prev->left;
                } else {
                    now->left = prev;
                    now = prev->right;
                }
            } else {
                now->val += sum;
                sum = now->val;
                now = now->left;
            }
        }
        return root;
    }
};