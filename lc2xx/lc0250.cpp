//--- Q: 250. Count Univalue Subtrees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder with compare with leaf value
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0, comp = 0;
        if (root)
            postorder(root, res, comp);
        return res;
    }
    void postorder(TreeNode *root, int &res, int &comp) {
        int lcomp = INT_MIN, rcomp = INT_MIN;
        comp = INT_MIN;
        if (!root->left && !root->right)
            lcomp = rcomp = root->val;
        if (root->left)
            postorder(root->left, res, lcomp);
        if (root->right)
            postorder(root->right, res, rcomp);
        if ((!root->left || lcomp == root->val)
            && (!root->right || rcomp == root->val)) {
            comp = max(lcomp, rcomp);
            ++res;
        }
    }
};

//--- method 2: postorder with compare parent and child node。
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        postorder(root, res, -1);
        return res;
    }
    bool postorder(TreeNode *root, int &res, int parent) {
        if (!root)
            return true;
        bool find = true;
        find &= postorder(root->left, res, root->val);
        find &= postorder(root->right, res, root->val);
        if (!find)
            return false;
        cout << "qq\n";
        ++res;
        return root->val == parent;
    }
};
