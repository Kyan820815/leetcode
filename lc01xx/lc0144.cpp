//--- Q: 144. Binary Tree Preorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: preorder recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> out;
        if (!root) return out;
        preorder(root, out);
        return out;
    }
    void preorder(TreeNode *root, vector<int> &out)
    {
    	out.push_back(root->val);
    	if (root->left) preorder(root->left, out);
    	if (root->right) preorder(root->right, out);
    }
};

//--- method 2: iterative solution using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> out;
        if (!root) return out;
       	preorder(root, out);
       	return out;
    }
    void preorder(TreeNode *root, vector<int> &out)
    {
    	stack<TreeNode*> sk;
    	TreeNode *cur;
    	sk.push(root);    		
    	while(!sk.empty())
    	{
    		cur = sk.top();
    		out.push_back(cur->val);
    		sk.pop();
    		if (cur->right) sk.push(cur->right);
    		if (cur->left) sk.push(cur->left);
    	}
    } 
};

//--- method 3: iterative solution using stack, my version
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> out;
       	preorder(root, out);
       	return out;
    }
    void preorder(TreeNode *root, vector<int> &out)
    {
    	stack<TreeNode*> sk;
    	TreeNode *cur;
    	cur = root;
    	while(cur || !sk.empty())
    	{
    		out.push_back(cur->val);
    		if (cur->right) sk.push(cur->right);
    		cur = cur->left;
    		if (!cur && !sk.empty())
    		{
    			cur = sk.top();
    			sk.pop();
    		} 
    	}
    } 
};

//--- method 4: morris travesal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> out;
        preorder(root, out);
        return out;
    }
    void preorder(TreeNode *root, vector<int> &out)
    {
    	TreeNode *cur, *prev;
        cur = root;
    	while(cur)
    	{
            if (cur->left)
            {
                prev = cur;
                cur = cur->left;
                while(cur->right && cur->right != prev)
                    cur = cur->right;

                if (!cur->right)
                {
                    out.push_back(prev->val);
                    cur->right = prev;
                    cur = prev->left;
                }
                else if (cur->right == prev)
                {
                    cur->right = NULL;
                    cur = prev->right;
                }
            }
            else
            {
                out.push_back(cur->val);
                cur = cur->right;
            }
    	}
    }
};