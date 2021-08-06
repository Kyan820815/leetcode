//--- Q: 0663. Equal Tree Partition

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

//--- method 1: two pass postorder
class Solution {
public:
    int sum = 0, find = 0;
    bool checkEqualTree(TreeNode* root) {
        sum = postorder(root);
        find = 0;
        if (sum&1) {
            return find;
        }
        postorder(root);
        return find;
    }
    int postorder(TreeNode *root) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left);
        }
        if (root->right) {
            rv = postorder(root->right);
        }
        if (root->left && lv == sum-lv || root->right && rv == sum-rv) {
            find = 1;
        }
        return root->val+lv+rv;
    }
};

//--- method 2: one pass and set
class Solution {
public:
    unordered_set<int> set;
    bool checkEqualTree(TreeNode* root) {
        int sum = postorder(root, true);
        return !(sum&1) && set.find(sum>>1) != set.end();
    }
    int postorder(TreeNode *root, bool isroot) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left, false);
        }
        if (root->right) {
            rv = postorder(root->right, false);
        }
        if (!isroot) {
            set.insert(root->val+lv+rv);
        }
        return root->val+lv+rv;
    }
};