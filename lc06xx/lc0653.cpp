//--- Q: 0653. Two Sum IV - Input is a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: 2 sum stack
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode *> left, right;
        auto now = root;
        while (now) {
            left.push_back(now);
            now = now->left;
        }
        now = root;
        while (now) {
            right.push_back(now);
            now = now->right;
        }
        while (1) {
            auto lnode = left.back();
            auto rnode = right.back();
            if (lnode == rnode) {
                break;
            }
            if (lnode->val + rnode->val < k) {
                left.pop_back();
                lnode = lnode->right;
                while (lnode) {
                    left.push_back(lnode);
                    lnode = lnode->left;
                }
            } else if (lnode->val + rnode->val > k) {
                right.pop_back();
                rnode = rnode->left;
                while (rnode) {
                    right.push_back(rnode);
                    rnode = rnode->right;
                }
            } else {
                return true;
            }
        }
        return false;      
    }
};

//--- method 2: map operation
class Solution {
public:
    unordered_set<int> set;
    bool find = false;
    bool findTarget(TreeNode* root, int k) {
        preorder(root, k);
        return find;
    }
    void preorder(TreeNode *root, int k) {
        if (set.find(root->val) != set.end()) {
            find = true;
        }
        set.insert(k-root->val);
        if (root->left) {
            preorder(root->left, k);
        }
        if (root->right) {
            preorder(root->right, k);
        }
    }
};