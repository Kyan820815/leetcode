//--- Q: 538. Convert BST to Greater Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inverse inorder recursion
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
    	int last = 0;
    	if (!root) return root;
    	inorder(root, last);
    	return root;
    }
    void inorder(TreeNode *root, int &last)
    {
    	if (root->right)
    		inorder(root->right, last);
		root->val += last;
		last = root->val;    	
    	if (root->left)
    		inorder(root->left, last);
    }
};

//--- method 2: inverse inorder stack iteration
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
    	stack<TreeNode *> sk;
    	TreeNode *now = root;
    	int sum = 0;
    	while (sk.size() || now)
    	{
    		while (now)
    		{
    			sk.push(now);
    			now = now->right;
    		}
    		now = sk.top();
    		now->val += sum;
            sk.pop();
    		sum = now->val;
    		now = now->left;
    	}
    	return root;
    }
};