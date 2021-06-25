//--- Q: 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int now = postorder.size()-1;
        if (!inorder.size()) return NULL;
    	return maketree(inorder, postorder, 0, inorder.size()-1, now);
    }
    TreeNode *maketree(vector<int> &inorder, vector<int> &postorder, int left, int right, int &now)
    {
    	int mid;
    	TreeNode *root = new TreeNode(postorder[now]);
    	for (int i = left; i <= right; ++i)
    	{
    		if (inorder[i] == postorder[now])
    		{
    			mid = i;
    			break;
    		}
    	}
    	if (mid+1 <= right)
    		root->right = maketree(inorder, postorder, mid+1, right, --now);
    	if (left <= mid-1)
    		root->left = maketree(inorder, postorder, left, mid-1, --now);
    	return root;
    }
};

//--- method 2: iteration
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<TreeNode *> sk;
        int ni = inorder.size()-1;
        TreeNode *root = NULL, *last = NULL;
        for (int i = postorder.size()-1; i >= 0;) {
            if (sk.size() && sk.back()->val == inorder[ni]) {
                last = sk.back();
                sk.pop_back();
                --ni;
            } else if (last) {
                last->left = new TreeNode(postorder[i--]);
                sk.push_back(last->left);
                last = NULL;
            } else {
                auto now = new TreeNode(postorder[i--]);
                if (sk.size()) {
                    sk.back()->right = now;
                }
                sk.push_back(now);
                if (!root) {
                    root = now;
                }
            }
        }
        return root;
    }
};