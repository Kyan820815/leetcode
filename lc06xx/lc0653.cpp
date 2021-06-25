//--- Q: 653. Two Sum IV - Input is a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: map operation
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        bool find = false;
        unordered_set<int> map;
        preorder(root, k, map, find);
        return find;
    }
    void preorder(TreeNode *root, int k, unordered_set<int> &map, bool &find)
    {
    	if (map.count(root->val))
    	{
    		find = true;
    		return;
    	}
    	map.insert(k-root->val);
    	if (root->left)
    		preorder(root->left, k, map, find);
    	if (root->right)
    		preorder(root->right, k, map, find);

    }
};

//--- method 2: 2 sum stack
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode *> sk1, sk2;
        TreeNode *now = root;
        while (now) {
            sk1.push_back(now);
            now = now->left;
        }
        now = root;
        while (now) {
            sk2.push_back(now);
            now = now->right;
        }
        while (sk1.size() && sk2.size()) {
            auto lnode = sk1.back();
            auto rnode = sk2.back();
            if (lnode == rnode) {
                return false;
            }
            if (lnode->val + rnode->val < k) {
                sk1.pop_back();
                lnode = lnode->right;
                while (lnode) {
                    sk1.push_back(lnode);
                    lnode = lnode->left;
                }
            } else if (lnode->val + rnode->val > k) {
                sk2.pop_back();
                rnode = rnode->left;
                while (rnode) {
                    sk2.push_back(rnode);
                    rnode = rnode->right;
                }
            } else {
                return true;
            }
        }
        return false;
    }
};