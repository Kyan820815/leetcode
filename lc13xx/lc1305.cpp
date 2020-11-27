//--- Q: 1305. All Elements in Two Binary Search Trees

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

//--- method 1: O(n) time one pass
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode *> sk1, sk2;
        vector<int> res;
        pushLeft(root1, sk1);
        pushLeft(root2, sk2);
        while (sk1.size() || sk2.size()) {
            vector<TreeNode *> &s = getS(sk1, sk2);
            TreeNode *now = s.back();
            s.pop_back();
            res.push_back(now->val);
            pushLeft(now->right, s);
        }
        return res;
    }
    void pushLeft(TreeNode *root, vector<TreeNode *> &sk) {
        while (root) {
            sk.push_back(root);
            root = root->left;
        }
    }
    vector<TreeNode*> &getS(vector<TreeNode *> &sk1, vector<TreeNode *> &sk2) {
        if (!sk1.size()) {
            return sk2;
        } else if (!sk2.size()) {
            return sk1;
        } else if (sk1.back()->val < sk2.back()->val) {
            return sk1;
        } else {
            return sk2;
        }
    }
};

//--- method 2: O(nlogn)
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs(root2);
        sort(res.begin(), res.end());
        return res;
    }
    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> res;
};