//--- Q: 662. Maximum Width of Binary Tree

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
    int widthOfBinaryTree(TreeNode* root) {
    	int qsize, res = INT_MIN, left, right;
        queue<pair<TreeNode *, int>> que;
        que.push({root,1});
        qsize = que.size();
        while (que.size())
        {
        	left = (qsize == 1) ? 1 : que.front().second;
        	for (int i = 0; i < qsize; ++i)
        	{
        		pair<TreeNode *, int> now = que.front();
        		right = (qsize == 1) ? 1 : now.second;
        		que.pop();
        		if (now.first->left)
        			que.push({now.first->left, right*2});
        		if (now.first->right)
        			que.push({now.first->right, right*2+1});
        	}
        	res = max(res, right-left+1);
        	qsize = que.size();
        }
        return res;
    }
};