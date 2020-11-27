//--- Q: 1339. Maximum Product of Splitted Binary Tree

//--- method 1: postorder
class Solution {
public:
    long long int M = 1e9 + 7;
    int maxProduct(TreeNode* root) {
        long long int sum = 0, res = 0;
        sum = multiply(root, res, sum);
        multiply(root, res, sum);
        return res % M;
    }
    int multiply(TreeNode *root, long long int &res, long long int &sum) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = multiply(root->left, res, sum);
        }
        if (root->right) {
            rv = multiply(root->right, res, sum);
        }
        int last = root->val + lv + rv;
        res = max(res, last * (sum - last));
        return last;
    }
};