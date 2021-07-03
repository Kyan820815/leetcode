//--- Q: 0101. Symmetric Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
    bool isSame(TreeNode *r1, *r2) {
        if (!r1 || !r2 || r1->val != r2->val) {
            return false;
        }
        return isSame(r1->left, r2->right) && issame(r1->right, r2->left);
    }
};

//--- method 2: double queues
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (q1.size() && q2.size()) {
            auto n1 = q1.front();
            auto n2 = q2.front();
            q1.pop();
            q2.pop();
            if (!n1 && !n2) {
                continue;
            }
            if (!n1 || !n2 || n1->val != n2->val) {
                return false;
            }
            if (n1) {
                q1.push(n1->left);
                q1.push(n1->right);
            }
            if (n2) {
                q2.push(n2->right);
                q2.push(n2->left);
            }
        }
        return true;
    }
};