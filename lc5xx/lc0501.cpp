//--- Q: 501. Find Mode in Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: track last node cnt
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
    	int max_cnt = 0, cnt = -1, last_val = INT_MAX;
    	vector<int> res;
        inorder(root, max_cnt, cnt, last_val, res);
        if (cnt > max_cnt)
        	return {last_val};
        else if (cnt == max_cnt)
        	res.push_back(last_val);
        return res;
    }
    void inorder(TreeNode *root, int &max_cnt, int &cnt, int &last_val, vector<int> &res)
    {
    	if (root->left)
            inorder(root->left, max_cnt, cnt, last_val, res);
    	if (root->val != last_val)
    	{
    		if (cnt >= max_cnt)
    		{
    			if (cnt > max_cnt)
    				res.resize(0);
    			res.push_back(last_val);
    			max_cnt = cnt;
    		}
    		cnt = 0;
    	}
    	++cnt;
    	last_val = root->val;
    	if (root->right)
            inorder(root->right, max_cnt, cnt, last_val, res);
    }
};