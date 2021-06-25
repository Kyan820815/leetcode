//--- Q: 897. Increasing Order Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: inroder iteration stack
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode *> sk;
        TreeNode *now = root, *last, *dummy = new TreeNode(-1);
        last = dummy;
       	while (sk.size() || now)
       	{
       		while (now)
       		{
       			sk.push(now);
       			now = now->left;
       		}

   			now = sk.top();
   			sk.pop();
   			//--- do something
			last->right = now;
			now->left = NULL;
			last = now;
   			now = now->right;
       	}
       	return dummy->right;
    }
};

//--- method 2: inorder recursion

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy = new TreeNode(-1), *last = dummy;
        inorder(root, &dummy, &last);
        return dummy->right;
    }
    void inorder(TreeNode *now, TreeNode **root, TreeNode **last) {
        if (now->left)
            inorder(now->left, root, last);
        (*last)->right = now;
        now->left = NULL;
        *last = now;
        if (now->right)
            inorder(now->right, root, last);
    }
};