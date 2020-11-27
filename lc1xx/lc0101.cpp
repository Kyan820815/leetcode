//--- Q: 101. Symmetric Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);
    }
    bool dfs(TreeNode *root1, TreeNode *root2)
    {
    	if (!root1 && !root2) return true;
    	if (!root1 && root2 || root1 && !root2 || root1->val != root2->val) return false;
    	return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
    }
};

//--- method 2: double queues
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	queue<TreeNode *> que1, que2;
    	if (!root) return true;
    	que1.push(root->left);
    	que2.push(root->right);
    	while (que1.size() && que2.size())
    	{
    		TreeNode *node1, *node2;
            node1 = que1.front();
            node2 = que2.front();
            que1.pop();
            que2.pop();
    		if (!node1 && !node2) continue;
    		if (!node1 && node2 || node1 && !node2)
    			return false;
    		if (node1->val != node2->val)
    			return false;
    		que1.push(node1->left);
    		que1.push(node1->right);
    		que2.push(node2->right);
    		que2.push(node2->left);
    	}
    	return true;
    }
};