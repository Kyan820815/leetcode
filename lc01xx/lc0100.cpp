//--- Q: 0100. Same Tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q || p->val != q->val) {
            return false;
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

//--- method 2: double queues
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while (q1.size() && q2.size()) {
            auto np = q1.front();
            auto nq = q2.front();
            q1.pop();
            q2.pop();
            if (np && nq) {
                if (np->val != nq->val) {
                    return false;
                }
                q1.push(np->left);
                q1.push(np->right);
                q2.push(nq->left);
                q2.push(nq->right);
            } else if (np || nq) {
                return false;
            }
        }
        return true;
    }
};