//--- Q: 1676. Lowest Common Ancestor of a Binary Tree IV

//--- method 1: postorder with set
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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode *> set(nodes.begin(), nodes.end());
        TreeNode *head = postorder(root, set);
        return head;
    }
    TreeNode *postorder(TreeNode *root, unordered_set<TreeNode *> &set) {
        if (!root || set.find(root) != set.end()) {
            return root;
        }
        TreeNode *lv = postorder(root->left, set);
        TreeNode *rv = postorder(root->right, set);
        if (lv && rv) {
            return root;
        } else if (lv) {
            return lv;
        } else {
            return rv;
        }
    }
};