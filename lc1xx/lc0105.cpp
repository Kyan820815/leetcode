//--- Q: 105. Construct Binary Tree from Preorder and Inorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: recursion
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int now = 0;
        if (preorder.empty()) return NULL;
        return dfs(now, 0, inorder.size()-1, preorder, inorder);
    }

    TreeNode *dfs(int &now, int start, int end, vector<int> &preorder, vector<int> &inorder)
    {
    	int root_idx;

        if (start > end) {
            return NULL;
        }
    	for (int i = start; i <= end; ++i) {
    		if (inorder[i] == preorder[now]) {
    			root_idx = i;
    			break;
    		}
    	}
    	auto root = new TreeNode(inorder[root_idx]);
        root->left = dfs(now, start root_idx-1, preorder, inporder);
        root->right = dfs(now, root_idx+1 end, preorder, inporder);
    	return root;
    }
};

//--- method 2: iteration
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
    	
    	stack<TreeNode *> sk;
    	int preorder_idx = 0, inorder_idx = 0;
        int now = 0;
        TreeNode *dummy = new TreeNode(INT_MAX);
        TreeNode *inorder_ptr = NULL;

        sk.push(dummy);
        while(preorder_idx < preorder.size())
        {
        	if (sk.top()->val == inorder[inorder_idx])
        	{
        		inorder_ptr = sk.top();
        		sk.pop();
        		inorder_idx++;
        	}
        	else if (inorder_ptr)
        	{
        		inorder_ptr->right = new TreeNode(preorder[preorder_idx]);
        		sk.push(inorder_ptr->right);
        		preorder_idx++;
        		inorder_ptr = NULL;
        	}
        	else
        	{
        		sk.top()->left = new TreeNode(preorder[preorder_idx]);
        		preorder_idx++;
        		sk.push(sk.top()->left);
        	} 
        }
        return dummy->left;
    }
};
