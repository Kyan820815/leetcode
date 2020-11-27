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

//--- method 2: map operation
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
		vector<int> res;
		inorder(root, res);
		int left = 0, right = res.size()-1;
		while (left < right)
		{
			if (res[left] + res[right] == k) return true;
			else if (res[left] + res[right] < k)
				++left;
			else
				--right;
		}
		return false;
    }
    void inorder(TreeNode *root, vector<int> &res)
    {
    	if (root->left)
    		inorder(root->left, res);
    	res.push_back(root->val);
    	if (root->right)
    		inorder(root->right, res);

    }
};