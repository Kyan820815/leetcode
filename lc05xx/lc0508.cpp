//--- Q: 0508. Most Frequent Subtree Sum

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
    unordered_map<int, int> map;
    vector<int> res;
    int maxcnt = 0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        postorder(root);
        return res;
    }
    int postorder(TreeNode *root) {
        int lv = 0, rv = 0;
        if (root->left) {
            lv = postorder(root->left);
        }
        if (root->right) {
            rv = postorder(root->right);
        }
        int sum = lv+rv+root->val;
        if (maxcnt < ++map[sum]) {
            maxcnt = map[sum];
            res.clear();
            res.push_back(sum);
        } else if (maxcnt == map[sum]) {
            res.push_back(sum);
        }
        return sum;
    }
};