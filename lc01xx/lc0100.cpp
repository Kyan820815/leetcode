//--- Q: 100. Same Tree

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
    bool isSameTree(TreeNode* p, TreeNode *q) {
        if (!p && !q) return true;
    	if (!p && q || p && !q || p->val != q->val) return false;
    	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

//--- method 2: double queues
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode *q) {
    	queue<TreeNode *> que1, que2;
    	que1.push(p);
    	que2.push(q);
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
    		que2.push(node2->left);
    		que2.push(node2->right);
    	}
    	return true;
    }
};