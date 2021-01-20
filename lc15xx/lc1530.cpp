//--- Q: 1530. Number of Good Leaf Nodes Pairs

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

//--- method 1: postorder
class Solution {
public:
    int res = 0;
    int countPairs(TreeNode* root, int distance) {
        if (root) {
            postorder(root, distance);
        }
        return res;
    }
    vector<int> postorder(TreeNode *root, int d) {
        vector<int> leaf, l, r;
        if (root->left) {
            l = postorder(root->left, d);
        }
        if (root->right) {
            r = postorder(root->right, d);
        }
        if (!root->left && !root->right) {
            leaf.push_back(1);
        }
        for (int i = 0; i < l.size(); ++i) {
            for (int j = 0; j < r.size(); ++j) {
                if (l[i]+r[j] <= d) {
                    ++res;
                }
            }
        }
        for (int i = 0; i < l.size(); ++i) {
            leaf.push_back(l[i]+1);
        }
        for (int i = 0; i < r.size(); ++i) {
            leaf.push_back(r[i]+1);
        }
        return leaf;
    }
};