//--- Q: 0988. Smallest String Starting From Leaf

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder
class Solution {
public:
    string res = "";
    string smallestFromLeaf(TreeNode* root) {
        string str = "";
        preorder(root, str);
        return res;
    }
    void preorder(TreeNode *root, string &str) {
        str += (root->val+'a');
        if (!root->left && !root->right) {
            auto tmp = str;
            reverse(tmp.begin(), tmp.end());
            if (!res.size() || res > tmp) {
                res = tmp;
            }
        }
        if (root->left) {
            preorder(root->left, str);
        }
        if (root->right) {
            preorder(root->right, str);
        }
        str.pop_back();
    }
};