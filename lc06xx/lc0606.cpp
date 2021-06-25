//--- Q: 606. Construct String from Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs and find the law
class Solution {
public:
    string tree2str(TreeNode* t) {
    	string res = "", lstr = "", rstr = "";
        if (!t) return "";
    	res += to_string(t->val);
		if (!t->left && t->right)
			res += "()";        
		if (t->left)
        {
            lstr = tree2str(t->left);
            res += "(" + lstr + ")";
        }
		if (t->right)
        {
			rstr = tree2str(t->right);
            res += "(" + rstr + ")";
        }
		return res;
    }
};