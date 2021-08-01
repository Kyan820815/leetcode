//--- Q: 0572. Subtree of Another Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder traversal
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (root->val == subRoot->val && sametree(root, subRoot)) {
            return true;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
    bool sametree(TreeNode *n1, TreeNode *n2) {
        if (!n1 && !n2) {
            return true;
        } else if (!n1 || !n2 || n1->val != n2->val) {
            return false;
        } else {
            return sametree(n1->left, n2->left) && sametree(n1->right, n2->right);
        }
    }
};

//--- method 2: string recording for substree
class Solution {
public:
    bool find = false;
    string sub = "";
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        sub = postorder(subRoot);
        postorder(root);
        return find;
    }
    string postorder(TreeNode *root) {
        string lstr = "", rstr = "";
        if (root->left) {
            lstr = postorder(root->left);
        }
        if (root->right) {
            rstr = postorder(root->right);
        }
        string str = lstr + " " + rstr + " " + to_string(root->val);
        if (str == sub) {
            find = true;
        }
        return str;
    }
};