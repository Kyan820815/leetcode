//--- Q: 1644. Lowest Common Ancestor of a Binary Tree II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder
class Solution {
public:
    int cnt = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca = postorder(root, p, q);
        return cnt == 2 ? lca : NULL;
    }
    TreeNode *postorder(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return root;
        }
        
        TreeNode *l = postorder(root->left, p, q);
        TreeNode *r = postorder(root->right, p, q);
        if (root == p || root == q) {
            ++cnt;
            return root;
        }
        if (l && r) {
            return root;
        } else if (l) {
            return l;
        } else {
            return r;
        }
    }
};