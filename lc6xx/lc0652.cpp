//--- Q: 652. Find Duplicate Subtrees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: postorder with recording string
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    	vector<TreeNode *> res;
    	unordered_map<string, int> map;
    	if (!root) return res;
    	string str = postorder(root, map, res);
    	return res;
    }
    string postorder(TreeNode *root, unordered_map<string, int> &map, vector<TreeNode *> &res)
    {
    	string strl = "#", strr = "#", str;
    	if (root->left)
    		strl = postorder(root->left, map, res);
    	if (root->right)
    		strr = postorder(root->right, map, res);
    	str = to_string(root->val) + "," + strl + "," + strr;
    	if (map[str] == 1)
    		res.push_back(root);
    	++map[str];
    	return str;
    }
};