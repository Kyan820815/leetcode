//--- Q: 663. Equal Tree Partition

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

//--- method 1: one pass postorder
class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_set<int> val;
        int sum = postorder(root, true, val);
        return !(sum % 2) && val.find(sum>>1) != val.end();
    }
    int postorder(TreeNode *root, bool isroot, unordered_set<int> &val) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left, false, val);
        }
        if (root->right) {
            rv = postorder(root->right, false, val);
        }
        int now = lv + rv + root->val;
        if (!isroot) {
            val.insert(now);
        }
        return now;
    }
};