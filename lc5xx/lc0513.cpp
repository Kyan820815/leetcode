//--- Q: 513. Find Bottom Left Tree Value

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bfs
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> que;
        que.push(root);
        int res;
        while (que.size()) {
            int qsize = que.size();
            res = que.front()->val;
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (now->left) {
                    que.push(now->left);
                }
                if (now->right) {
                    que.push(now->right);
                }
            }
        }
        return res;
    }
};

//--- method 2: dfs
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
    	int first, maxh = -1, height = 0;
    	dfs(root, height, maxh, first);
    	return first;
    }
    void dfs(TreeNode *root, int height, int &maxh, int &first)
    {
    	if (height > maxh)
    	{
    		first = root->val;
    		maxh = height;
    	}
    	if (root->left)
    		dfs(root->left, height+1, maxh, first);
    	if (root->right)
    		dfs(root->right, height+1, maxh, first);
    }
};