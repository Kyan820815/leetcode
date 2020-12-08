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
        while (1) {
            while (root1) {
                sk1.push_back(root1);
                root1 = root1->left;
            }
            while (root2) {
                sk2.push_back(root2);
                root2 = root2->left;
            }
            if (!sk1.size() && !sk2.size()) {
                break;
            }
            TreeNode *now1 = sk1.size() ? sk1.back() : NULL;
            TreeNode *now2 = sk2.size() ? sk2.back() : NULL;
            if (!now1 || now1 && now2 && now1->val > now2->val) {
                res.push_back(now2->val);
                sk2.pop_back();
                root2 = now2->right;
            } else if (!now2 || now1 && now2 && now1->val <= now2->val) {
                res.push_back(now1->val);
                sk1.pop_back();
                root1 = now1->right;
            }
        }
        return res;
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