//--- Q: 617. Merge Two Binary Trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs, clean code, better
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1)
            return t2;
        if (!t2)
            return t1;
        TreeNode *now = new TreeNode(t1->val + t2->val);
        now->left = mergeTrees(t1->left, t2->left);
        now->right = mergeTrees(t1->right, t2->right);
        return now;
    }
};

//--- method 2: dfs
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    	if (!t1 && !t2) return NULL;
    	TreeNode *node;
    	if (t1 && t2)
    	{
    		node = t1;
    		node->val += t2->val;
    		node->left = mergeTrees(t1->left, t2->left);
    		node->right = mergeTrees(t1->right, t2->right);
    	}
    	else if (t1 && !t2)
    	{
    		node = t1;
    		node->left = mergeTrees(t1->left, NULL);
    		node->right = mergeTrees(t1->right, NULL);

    	}
    	else if (!t1 && t2)
    	{
    		node = t2;
    		node->left = mergeTrees(NULL, t2->left);
    		node->right = mergeTrees(NULL, t2->right);

    	}
        return node;
    }
};