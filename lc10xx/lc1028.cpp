//--- Q: 1028. Recover a Tree From Preorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: stack iteration with recording depth
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        stack<pair<TreeNode *,int>> sk;
        int depth, num, idx = 0;
        TreeNode *root = NULL;
        while (idx < S.size())
        {
        	num = depth = 0;
        	while ((S[idx] > '9' || S[idx] < '0'))
        	{
        		++idx;
        		++depth;
        	}
        	while (idx < S.size() && S[idx] != '-')
        	{
        		num = num*10 + (S[idx]-'0');
        		++idx;
        	}
        	TreeNode *now = new TreeNode(num);
        	if (!root) root = now;
        	if (sk.size() && sk.top().second+1 == depth)
				sk.top().first->left = now;
        	else if (sk.size())
        	{
        		while (sk.size() && sk.top().second != depth-1)
        			sk.pop();
        		sk.top().first->right = now;
        	}
        	sk.push({now, depth});
        }
        return root;
    }
};

//--- method 2: stack iteration with using stack size for depth
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode *> sk;
        int depth, num, idx = 0;
        TreeNode *root = NULL;
        while (idx < S.size())
        {
        	num = depth = 0;
        	while ((S[idx] > '9' || S[idx] < '0'))
        	{
        		++idx;
        		++depth;
        	}
        	while (idx < S.size() && S[idx] != '-')
        	{
        		num = num*10 + (S[idx]-'0');
        		++idx;
        	}
        	TreeNode *now = new TreeNode(num);
        	if (sk.size())
        	{
        		if (sk.size() == depth)
        			sk.back()->left = now;
        		else
        		{
        			while (sk.size() > depth)
        				sk.pop_back();
        			sk.back()->right = now;
        		}
        	}
        	sk.push_back(now);
        }
        return sk[0];
    }
};