//--- Q: 1038. Binary Search Tree to Greater Sum Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inorder morris traversal
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        auto now = root;
        int sum = 0;
        while (now) {
            if (now->right) {
                auto prev = now;
                now = now->right;
                while (now->left && now->left != prev) {
                    now = now->left;
                }
                if (now->left) {
                    now->left = nullptr;
                    now = prev->left;
                    prev->val += sum;
                    sum = prev->val;
                } else {
                    now->left = prev;
                    now = prev->right;
                }
            } else {
                now->val += sum;
                sum = now->val;
                now = now->left;
            }
        }
        return root;
    }
};

//--- method 2: inorder recursion
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
		int sum = 0;
		if (!root) return root;
		dfs(root, sum);
		return root;
    }
    void dfs(TreeNode *root, int &sum)
    {
    	if (root->right)
    		dfs(root->right, sum);
    	sum += root->val;
    	root->val = sum;
    	if (root->left)
    		dfs(root->left, sum);
    }
};

//--- method 3: inorder stack
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode *> sk;
        auto now = root;
        int sum = 0;
        while (now || sk.size()) {
            while (now) {
                sk.push_back(now);
                now = now->right;
            }
            now = sk.back();
            sk.pop_back();
            now->val += sum;
            sum = now->val;
            now = now->left;
        }
        return root;
    }
};